package com.glory.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Clan {
    private Integer id;
    private String name;
    private String teamLeader;
    private String roleName;
}
