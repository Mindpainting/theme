package com.springboot.repository;

import com.springboot.entity.Idiom;

import java.util.List;

public interface IdiomRepository {
    List<Idiom> queryAll();

    Idiom queryById(Integer id);

    void insert(Idiom idiom);

    void update(Idiom idiom);

    void deleteById(Integer id);
}
