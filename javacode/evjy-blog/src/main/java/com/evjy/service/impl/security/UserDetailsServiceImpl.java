package com.evjy.service.impl.security;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.evjy.entity.SysUser;
import com.evjy.mapper.SysMenuMapper;
import com.evjy.mapper.SysUserMapper;
import com.evjy.model.AuthUser;
import com.evjy.model.LoginUser;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.stereotype.Service;

import java.util.Objects;
import java.util.Set;

/**
 * @Author Evjy
 * @Date 2024/3/15 15:11
 * @Description 用户认证
 */

@Service
public class UserDetailsServiceImpl implements UserDetailsService {
    private static final Logger log = LoggerFactory.getLogger(UserDetailsServiceImpl.class);

    @Autowired
    private SysUserMapper userMapper;

    @Autowired
    private SysMenuMapper menuMapper;

    @Override
    public UserDetails loadUserByUsername(String username) {
        LambdaQueryWrapper<SysUser> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        lambdaQueryWrapper.eq(SysUser::getUserName, username);
        SysUser sysUser = userMapper.selectOne(lambdaQueryWrapper);

        Set<String> permissionsList;
        if (Objects.isNull(sysUser)) {
            log.info("登录用户{}不存在", username);
            throw new RuntimeException("登录用户不存在");
        } else {
            // 封装用户权限信息
            permissionsList = menuMapper.selectPermsByUserId(sysUser.getUserId());
        }
        return new LoginUser(new AuthUser(sysUser.getUserId(), sysUser.getUserName(), sysUser.getPassword()), permissionsList);
    }
}
