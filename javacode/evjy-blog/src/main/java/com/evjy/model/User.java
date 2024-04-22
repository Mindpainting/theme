package com.evjy.model;

import com.evjy.common.validation.validate.PositiveInteger;
import jakarta.validation.constraints.Email;
import jakarta.validation.constraints.NotEmpty;
import jakarta.validation.constraints.Size;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @Author Evjy
 * @Date 2024/4/19 13:16
 * @Description 用于测试参数校验
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class User {
    @NotEmpty(message = "用户名不能为空")
    private String username;

    @NotEmpty(message = "密码不能为空")
    private String password;

    @PositiveInteger(message = "年龄必须为正整数")
    private Integer age;

    @Size(min = 0, max = 1, message = "性别只能为男或女")
    private String gender;

    @Email(regexp = "^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$", message = "邮箱格式不正确")
    private String email;

    private String address;

    //@Max(value = 11, message = "电话号码不能超过11位")
    private String phone;
}
