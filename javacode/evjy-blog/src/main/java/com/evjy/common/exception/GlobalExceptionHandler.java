package com.evjy.common.exception;

import com.evjy.model.ApiResult;
import jakarta.servlet.http.HttpServletRequest;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.HttpRequestMethodNotSupportedException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RestControllerAdvice;

/**
 * @Author Evjy
 * @Date 2024/4/19 18:53
 * @Description 全局异常处理器
 * 一般会先进行精确匹配，精确匹配未成功，则进行模糊匹配
 */

@Slf4j
@RestControllerAdvice(annotations = RestController.class)
public class GlobalExceptionHandler {

    /**
    * @description 请求方式不支持
    *
    * @param e 异常对象
    * @param request http 请求
    */
    @ExceptionHandler(HttpRequestMethodNotSupportedException.class)
    public ApiResult handleHttpRequestMethodNotSupported(HttpRequestMethodNotSupportedException e, HttpServletRequest request)
    {
        String requestURI = request.getRequestURI();
        log.error("请求地址'{}',不支持'{}'请求", requestURI, e.getMethod());
        return ApiResult.error(e.getMessage());
    }

    /**
     * @description 处理空指针异常
     *
     * @param e 异常对象
     */
    @ExceptionHandler(NullPointerException.class)
    public ApiResult handleNullPointerException(NullPointerException e) {
        log.error("空指针异常: ", e);
        return new ApiResult(500, "空指针异常", e.getMessage());
    }


    /**
    * @description 处理未精确匹配的异常
    *
    * @param e 异常对象
    */
    @ExceptionHandler(Exception.class)
    public ApiResult handleException(Exception e) {
        log.error("处理未精确匹配的异常: ", e);
        return new ApiResult(500, "系统异常，请联系管理员", e.getMessage());
    }
}
