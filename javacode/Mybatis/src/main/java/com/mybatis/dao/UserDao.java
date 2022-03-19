package com.mybatis.dao;

import com.mybatis.entity.User;
import org.apache.ibatis.annotations.Param;

import java.util.List;
import java.util.Map;

public interface UserDao {
    List<User> queryAll();

    User queryById(Integer id);

    User queryByUser(User user);

    User queryByMap(Map map);

    List<User> queryByParams(@Param("id") Integer id, @Param("name") String name);

    void insertUser(User user);

    void deleteUser(Integer id);

    void updateUser(User user);

    List<User> queryByIds(@Param("ids") Integer[] ids);
}
