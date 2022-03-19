package com.glory;

import com.glory.dao.ClanDao;
import com.glory.dao.PlayerDao;
import com.glory.entity.Clan;
import com.glory.entity.Player;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

@SuppressWarnings("all")
public class GloryTest {

    private SqlSession sqlSession;

    @Before
    public void init() throws IOException {
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
        sqlSession = sqlSessionFactory.openSession();
    }

    @Test
    public void clanDaoTest() {
        ClanDao clanDao = sqlSession.getMapper(ClanDao.class);
        List<Clan> clans = clanDao.queryAllClan();
        for (Clan clan : clans) {
            System.out.println(clan);
        }
    }

    @Test
    public void playerDaoTest() {
        PlayerDao playerDao = sqlSession.getMapper(PlayerDao.class);

/*        List<Player> players = playerDao.queryPlayerByClanId(7);
        for (Player player : players) {
            System.out.println(player);
        }*/

/*        Player player = playerDao.queryPlayerById(1);
        System.out.println(
                "id = " + player.getId() + ", " +
                "name = " + player.getName() + ", " +
                "roleName = " + player.getRoleName() + ", " +
                "clan = " + player.getClan().getName() + ", " +
                "profession = " + player.getProfession().getName()
        );*/

        List<Player> players = playerDao.queryAllPlayer();
        for (Player player : players) {
            System.out.println(player);
        }
    }

    @After
    public void destroy() {
        // 提交事务
        sqlSession.commit();
        sqlSession.close();
    }

}

