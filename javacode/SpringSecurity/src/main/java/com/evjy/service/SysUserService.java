package com.evjy.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.evjy.entity.ApiResult;
import com.evjy.entity.db.SysUser;

public interface SysUserService extends IService<SysUser> {

    ApiResult login(SysUser user);

    ApiResult logout();
}
