package com.evjy.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.evjy.entity.db.SysMenu;
import org.apache.ibatis.annotations.Mapper;

import java.util.HashSet;

@Mapper
public interface SysMenuMapper extends BaseMapper<SysMenu> {

    HashSet<String> selectPermsByUserId(Long userId);

}




