package com.springmvc.entity;

import lombok.Data;

import java.util.Map;

@Data
public class UserMap {
    private Map<String, User> userMap;
}
