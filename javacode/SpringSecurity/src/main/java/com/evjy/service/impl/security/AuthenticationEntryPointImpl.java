package com.evjy.service.impl.security;

import com.alibaba.fastjson2.JSON;
import com.evjy.entity.ApiResult;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.springframework.http.HttpStatus;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.web.AuthenticationEntryPoint;
import org.springframework.stereotype.Component;

import java.io.IOException;

/**
 * @Author Evjy
 * @Date 2024/3/25 13:13
 * @Description Spring Security 异常处理自定义实现类
 */

@Component
public class AuthenticationEntryPointImpl implements AuthenticationEntryPoint {
    @Override
    public void commence(HttpServletRequest request, HttpServletResponse response, AuthenticationException authException) throws IOException, ServletException {
        ApiResult apiResult = new ApiResult(HttpStatus.UNAUTHORIZED.value(), "用户认证失败");
        String jsonString = JSON.toJSONString(apiResult);
        response.setStatus(200);
        response.setContentType("application/json;charset=UTF-8");
        response.getWriter().print(jsonString);
    }
}
