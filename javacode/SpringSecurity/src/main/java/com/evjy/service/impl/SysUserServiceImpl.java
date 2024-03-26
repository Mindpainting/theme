package com.evjy.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.evjy.common.constant.Constants;
import com.evjy.common.toolkit.Jwt;
import com.evjy.common.toolkit.RedisCache;
import com.evjy.entity.ApiResult;
import com.evjy.entity.ca.LoginUser;
import com.evjy.entity.db.SysUser;
import com.evjy.mapper.SysUserMapper;
import com.evjy.service.SysUserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.Objects;
import java.util.concurrent.TimeUnit;

@Service
public class SysUserServiceImpl extends ServiceImpl<SysUserMapper, SysUser> implements SysUserService {

    @Autowired
    AuthenticationManager authenticationManager;

    @Autowired
    RedisCache redisCache;


    /**
     * @param user 用户
     * @return com.evjy.entity.ApiResult
     * @description 登录
     */
    @Override
    public ApiResult login(SysUser user) {
        // 认证用户
        UsernamePasswordAuthenticationToken authentication = new UsernamePasswordAuthenticationToken(user.getUserName(), user.getPassword());
        Authentication authenticate = authenticationManager.authenticate(authentication);
        if (Objects.isNull(authenticate)) {
            throw new RuntimeException("登录失败");
        }

        // 获取用户 id
        LoginUser loginUser = (LoginUser) authenticate.getPrincipal();
        Long userId = loginUser.getUser().getUserId();

        // 根据用户 id 生成 jwt
        String jwt = Jwt.generateJWT(userId.toString());
        HashMap<String, String> map = new HashMap<>();
        map.put("token", jwt);

        // 存入 redis
        redisCache.setCacheObject(Constants.LOGIN_TOKEN_KEY_PREFIX + userId, loginUser, 30, TimeUnit.MINUTES);
        return new ApiResult(200, "登录成功", map);
    }


    /**
     * @return com.evjy.entity.ApiResult
     * @description 退出
     */
    @Override
    public ApiResult logout() {
        // 获取 SecurityContextHolder 中用户的 id
        Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
        LoginUser loginUser = (LoginUser) authentication.getPrincipal();
        Long userId = loginUser.getUser().getUserId();

        // 删除 redis 中用户数据
        if (redisCache.deleteObject(Constants.LOGIN_TOKEN_KEY_PREFIX + userId))
            return new ApiResult(200, "退出成功");
        else
            return new ApiResult(500, "token删除失败");
    }
}




