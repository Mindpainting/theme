package com.evjy.service.impl.security;

import com.alibaba.fastjson2.JSON;
import com.evjy.entity.ApiResult;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.springframework.http.HttpStatus;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.security.web.access.AccessDeniedHandler;
import org.springframework.stereotype.Component;

import java.io.IOException;

/**
 * @Author Evjy
 * @Date 2024/3/25 14:17
 * @Description Spring Security 异常处理自定义实现类
 */

@Component
public class AccessDeniedHandlerImpl implements AccessDeniedHandler {
    @Override
    public void handle(HttpServletRequest request, HttpServletResponse response, AccessDeniedException accessDeniedException) throws IOException, ServletException {
        ApiResult apiResult = new ApiResult(HttpStatus.FORBIDDEN.value(), "权限不足");
        String jsonString = JSON.toJSONString(apiResult);
        response.setStatus(200);
        response.setContentType("application/json;charset=UTF-8");
        response.getWriter().print(jsonString);
    }
}
