package com.evjy.common.filter;

import com.evjy.common.constant.Constants;
import com.evjy.common.toolkit.Jwt;
import com.evjy.common.toolkit.RedisCache;
import com.evjy.entity.ca.LoginUser;
import jakarta.servlet.FilterChain;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Component;
import org.springframework.util.StringUtils;
import org.springframework.web.filter.OncePerRequestFilter;

import java.io.IOException;
import java.util.Objects;

/**
 * @Author Evjy
 * @Date 2024/3/22 14:10
 * @Description JWT 认证
 */

@Component
public class JwtAuthenticationTokenFilter extends OncePerRequestFilter {

    @Autowired
    RedisCache redisCache;

    @Override
    protected void doFilterInternal(HttpServletRequest request, HttpServletResponse response, FilterChain filterChain) throws ServletException, IOException {

        // 获取 token
        String token = request.getHeader("token");

        // hasText(token) return str != null && !str.isBlank();
        if (!StringUtils.hasText(token)) {
            // token 为空，放行
            filterChain.doFilter(request, response);
        } else {
            // 解析 token
            String userId;
            try {
                userId = Jwt.parseJWT(token);
            } catch (Exception e) {
                throw new RuntimeException("token错误", e);
            }
            // 从 redis 中获取用户信息
            if (StringUtils.hasText(userId)) {
                String redisKey = Constants.LOGIN_TOKEN_KEY_PREFIX + userId;
                LoginUser loginUser = (LoginUser) redisCache.getCacheObject(redisKey);
                if (Objects.isNull(loginUser)) {
                    throw new RuntimeException("用户未登录");
                }
                // 存入 SecurityContextHolder
                // 三个参数的构造函数会设置用户为已认证状态，两个参数的不会
                // TODO 获取权限信息封装到 authenticationToken 中
                UsernamePasswordAuthenticationToken authenticationToken = new UsernamePasswordAuthenticationToken(loginUser, null, loginUser.getAuthorities());
                SecurityContextHolder.getContext().setAuthentication(authenticationToken);
                // 放行
                filterChain.doFilter(request, response);
            }
        }

    }
}
