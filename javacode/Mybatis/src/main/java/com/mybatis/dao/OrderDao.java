package com.mybatis.dao;

import com.mybatis.entity.Order;

import java.util.List;

public interface OrderDao {
    List<Order> queryAll();

    List<Order> queryById(Integer id);

}
