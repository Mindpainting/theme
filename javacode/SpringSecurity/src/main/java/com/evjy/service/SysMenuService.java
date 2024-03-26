package com.evjy.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.evjy.entity.db.SysMenu;

import java.util.HashSet;

public interface SysMenuService extends IService<SysMenu> {

    /**
     * @param userId 用户 id
     * @description 根据 id 查询用户的权限列表
     */
    HashSet<String> selectPermsByUserId(Long userId);
}
