package com.springmvc.converter;

import com.springmvc.entity.User;
import org.springframework.core.convert.converter.Converter;

public class UserConverter implements Converter<String, User> {

    @Override
    public User convert(String s) {
        String[] split = s.split("-");
        User user = new User();
        user.setUsername(split[0]);
        user.setPassword(Integer.parseInt(split[1]));
        return user;
    }
}
