package com.evjy.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.evjy.common.constant.JwtEnum;
import com.evjy.common.toolkit.Jwt;
import com.evjy.common.toolkit.RedisCache;
import com.evjy.entity.SysUser;
import com.evjy.mapper.SysUserMapper;
import com.evjy.model.ApiResult;
import com.evjy.model.AuthUser;
import com.evjy.model.LoginUser;
import com.evjy.service.SysUserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.Objects;
import java.util.concurrent.TimeUnit;

@Service
public class SysUserServiceImpl extends ServiceImpl<SysUserMapper, SysUser> implements SysUserService {

    @Autowired
    SysUserMapper sysUserMapper;

    @Autowired
    PasswordEncoder passwordEncoder;

    @Autowired
    AuthenticationManager authenticationManager;

    @Autowired
    RedisCache redisCache;

    /**
     * @param authUser 认证授权用户
     * @description 登录
     */
    @Override
    public ApiResult login(AuthUser authUser) {
        // 认证用户
        UsernamePasswordAuthenticationToken authentication = new UsernamePasswordAuthenticationToken(authUser.getUserName(), authUser.getPassword());
        // 调用 authenticate() 后，会去调用自定义的 UserDetailsServiceImpl 里面的 loadUserByUsername() 方法
        Authentication authenticate = authenticationManager.authenticate(authentication);
        if (Objects.isNull(authenticate)) {
            throw new RuntimeException("认证失败");
        } else {
            // 获取用户 id
            LoginUser loginUser = (LoginUser) authenticate.getPrincipal();
            Long userId = loginUser.getAuthUser().getUserId();

            // 根据用户 id 生成 jwt
            String jwt = Jwt.generateToken(userId.toString());
            HashMap<String, String> map = new HashMap<>();
            map.put("token", jwt);

            // 存入 redis
            redisCache.setCacheObject(JwtEnum.LOGIN_TOKEN_KEY_PREFIX.getValue() + userId, loginUser, 30, TimeUnit.DAYS);
            return new ApiResult(200, "登录成功", map);
        }


    }

    /**
     * @description 退出登录
     */
    @Override
    public ApiResult logout() {
        // 获取 SecurityContextHolder 中用户的 id
        Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
        LoginUser loginUser = (LoginUser) authentication.getPrincipal();
        Long userId = loginUser.getAuthUser().getUserId();

        // 删除 redis 中存入的用户数据
        if (redisCache.deleteObject(JwtEnum.LOGIN_TOKEN_KEY_PREFIX.getValue() + userId))
            return new ApiResult(200, "退出成功");
        else
            return new ApiResult(500, "退出失败");
    }

    /**
     * @param sysUser 系统用户
     * @description 用户注册
     */
    @Override
    public ApiResult register(SysUser sysUser) {
        String userName = sysUser.getUserName();
        if (sysUserMapper.selectCount(new LambdaQueryWrapper<SysUser>().eq(SysUser::getUserName, userName)) > 0) {
            return new ApiResult(500, "用户名已被占用");
        } else {
            // 对用户的密码进行加密后存入数据库
            sysUser.setPassword(passwordEncoder.encode(sysUser.getPassword()));

            // TODO 这里不知道 mybatis-plus 执行 insert() 后的返回值是什么
            sysUserMapper.insert(sysUser);

            return new ApiResult(200, "注册成功");
        }
    }

    /**
     * @param userId 用户 id
     * @description 注销用户
     */
    @Override
    public ApiResult logoff(Long userId) {
        // TODO 不知道返回的整数是啥
        sysUserMapper.deleteById(userId);
        return new ApiResult(200, "注销成功");
    }
}




