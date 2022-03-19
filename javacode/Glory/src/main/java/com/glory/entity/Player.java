package com.glory.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Player {
    private Integer id;
    private String name;
    private String roleName;
    private Integer clanId;
    private Integer professionId;
    private String weapon;
    private String skill;
    private Integer isTeamLeader;

    private Clan clan;
    private Profession profession;
}
