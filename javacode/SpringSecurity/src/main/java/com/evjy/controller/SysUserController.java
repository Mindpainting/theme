package com.evjy.controller;

import com.evjy.entity.ApiResult;
import com.evjy.entity.db.SysUser;
import com.evjy.service.SysUserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.*;

/**
 * @Author Evjy
 * @Date 2024/3/14 19:32
 * @Description 用户操作
 */
@RestController
@CrossOrigin
@RequestMapping("/user")
public class SysUserController {

    @Autowired
    SysUserService userService;

    @GetMapping("/sample")
    public ApiResult sample() {
        return new ApiResult(200, "hello");
    }

    /**
     * @return void
     * @description 登录
     */
    @PostMapping("/login")
    public ApiResult login(@RequestParam("username") String username,
                           @RequestParam("password") String password) {
        SysUser sysUser = new SysUser();
        sysUser.setUserName(username);
        sysUser.setPassword(password);

        return userService.login(sysUser);
    }

    /**
     * @return ApiResult
     * @description 退出
     */
    @PostMapping("/logout")
    public ApiResult logout() {
        return userService.logout();
    }
}
