package com.evjy.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.evjy.entity.SysUser;
import com.evjy.model.ApiResult;
import com.evjy.model.AuthUser;

public interface SysUserService extends IService<SysUser> {

    ApiResult login(AuthUser authUser);

    ApiResult logout();

    ApiResult register(SysUser sysUser);

    ApiResult logoff(Long userId);
}
