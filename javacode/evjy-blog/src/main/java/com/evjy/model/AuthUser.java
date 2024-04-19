package com.evjy.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serial;
import java.io.Serializable;

/**
 * @Author Evjy
 * @Date 2024/3/26 14:24
 * @Description 用于 Spring Security 认证授权的用户数据模型
 */

@Data
@AllArgsConstructor
@NoArgsConstructor
public class AuthUser implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    /**
     * 用户 id
     */
    private Long userId;

    /**
     * 用户名（昵称）
     */
    private String userName;

    /**
     * 密码
     */
    private String password;

    public AuthUser(String userName, String password) {
        this.userName = userName;
        this.password = password;
    }
}
