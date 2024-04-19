package com.evjy.controller;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.evjy.entity.SysUser;
import com.evjy.model.ApiResult;
import com.evjy.model.AuthUser;
import com.evjy.service.SysUserService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * @Author Evjy
 * @Date 2024/3/14 19:32
 * @Description 用户操作
 */

@RestController
@CrossOrigin
@Slf4j
@RequestMapping("/user")
public class SysUserController {

    @Autowired
    SysUserService userService;

    @GetMapping("/sample")
    public ApiResult sample() {
        log.error("error");
        return new ApiResult(200, "hello");
    }

    /**
     * @param username 用户名
     * @param password 密码
     * @description 登录
     */
    @PostMapping("/login")
    public ApiResult login(@RequestParam("username") String username, @RequestParam("password") String password) {
        AuthUser authUser = new AuthUser(username, password);
        return userService.login(authUser);
    }

    /**
     * @description 退出登录
     */
    @PostMapping("/logout")
    public ApiResult logout() {
        return userService.logout();
    }

    /**
     * @param username 用户名
     * @param password 密码
     * @description 注册
     */
    @PostMapping("/register")
    public ApiResult register(@RequestParam("username") String username, @RequestParam("password") String password) {
        SysUser sysUser = new SysUser(username, password);
        return userService.register(sysUser);
    }

    /**
     * @param userId 用户 id
     * @description 注销
     */
    @DeleteMapping("/logoff")
    public ApiResult logoff(@RequestParam("userId") Long userId) {
        return userService.logoff(userId);
    }


    /**
     * @param currentPage 当前页码
     * @param pageSize    每页数据
     * @description 查询所有用户
     */
    @GetMapping("/all/{currentPage}/{pageSize}")
    public ApiResult getAllUsers(@PathVariable(value = "currentPage") long currentPage, @PathVariable(value = "pageSize") long pageSize) {
        Page<SysUser> page = Page.of(currentPage, pageSize);
        userService.page(page, null);
        return ApiResult.success(page);
    }

}
