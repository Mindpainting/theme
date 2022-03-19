package com.glory.dao;

import com.glory.entity.Player;

import java.util.List;

public interface PlayerDao {
    List<Player> queryAllPlayer();

    List<Player> queryPlayerByClanId(Integer clanId);


    // 根据 id 查询玩家的姓名，游戏 id，所属战队，角色职业，角色使用武器
    Player queryPlayerById(Integer id);

    // 根据 ids 查询多个玩家的姓名，游戏 id，所属战队，角色职业，角色使用武器
    Player queryPlayerByIds(Integer[] ids);

}
