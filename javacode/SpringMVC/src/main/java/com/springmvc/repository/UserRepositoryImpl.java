package com.springmvc.repository;

import com.springmvc.entity.User;
import org.springframework.stereotype.Repository;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

@Repository
public class UserRepositoryImpl implements UserRepository {
    private static final Map<Integer, User> userMap;

    static {
        userMap = new HashMap<>();
        userMap.put(1, new User("TTY", 123, null));
        userMap.put(2, new User("SSH", 147, null));
        userMap.put(3, new User("FGD", 159, null));
    }

    @Override
    public Collection<User> queryAll() {
        return userMap.values();
    }

    @Override
    public User queryById(int id) {
        return userMap.get(id);
    }

    @Override
    public void saveOrUpdate(User user) {
    }

    @Override
    public void deleteById(int id) {
        userMap.remove(id);
    }
}
