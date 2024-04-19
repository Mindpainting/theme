package com.evjy.common.constant;


import lombok.AllArgsConstructor;
import lombok.Getter;

@Getter
@AllArgsConstructor
// 使用枚举替代常规的在类里定义常量，可以保证类型安全
public enum JwtEnum {
    // redis key prefix
    LOGIN_TOKEN_KEY_PREFIX("login_token_");

    private final String value;

}
