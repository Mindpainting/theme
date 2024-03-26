package com.evjy.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.evjy.entity.db.SysMenu;
import com.evjy.mapper.SysMenuMapper;
import com.evjy.service.SysMenuService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.HashSet;

@Service
public class SysMenuServiceImpl extends ServiceImpl<SysMenuMapper, SysMenu> implements SysMenuService {

    @Autowired
    SysMenuMapper sysMenuMapper;

    @Override
    public HashSet<String> selectPermsByUserId(Long userId) {
        return sysMenuMapper.selectPermsByUserId(userId);
    }
}




