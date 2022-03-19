package com.springmvc.repository;

import com.springmvc.entity.User;

import java.util.Collection;

public interface UserRepository {
    Collection<User> queryAll();

    User queryById(int id);

    void saveOrUpdate(User user);

    void deleteById(int id);
}
