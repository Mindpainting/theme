package com.evjy.common.exception.custom;

import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;

import java.io.Serial;

/**
 * @Author Evjy
 * @Date 2024/4/19 19:49
 * @Description 业务异常
 * "@EqualsAndHashCode(callSuper = true)" 表示在生成 equals 和 hashCode 方法时，将父类对象也考虑在内
 * 解决 lombok 警告 Generating equals/hashCode implementation but without a call to superclass, even though this class does not extend java.lang.Object. If this is intentional, add '(callSuper=false)' to your type.
 */

@EqualsAndHashCode(callSuper = true)
@Data
@NoArgsConstructor
public final class ServiceException extends RuntimeException {

    @Serial
    private static final long serialVersionUID = 1L;

    /**
     * 错误码
     */
    private Integer code;

    /**
     * 错误提示
     */
    private String message;

    /**
     * 错误明细，内部调试错误
     */
    private String detailMessage;

    public ServiceException(String message)
    {
        this.message = message;
    }

    public ServiceException(Integer code, String message)
    {
        this.code = code;
        this.message = message;
    }

    public ServiceException setMessage(String message)
    {
        this.message = message;
        return this;
    }

    public ServiceException setDetailMessage(String detailMessage)
    {
        this.detailMessage = detailMessage;
        return this;
    }

}
