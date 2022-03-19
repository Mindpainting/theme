package com.mybatis;

import com.mybatis.dao.OrderDao;
import com.mybatis.dao.UserDao;
import com.mybatis.entity.Order;
import com.mybatis.entity.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@SuppressWarnings("all")
public class MybatisTest {
    private SqlSession sqlSession;

    @Before
    public void init() throws IOException {
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
        sqlSession = sqlSessionFactory.openSession();
    }

    @Test
    public void userDaoTest() {
        UserDao userDao = sqlSession.getMapper(UserDao.class);
        List<User> users = userDao.queryAll();
        for (User user : users) {
            System.out.println(user);
        }

        // System.out.println(userDao.queryById(2));

        // System.out.println(userDao.queryByUser(new User(3, "沉飞燕", 25, "杭州")));

/*        Map map = new HashMap();
        map.put("id", 1);
        map.put("name", "风铃");
        map.put("age", 18);
        map.put("address", "北京");
        System.out.println(userDao.queryByMap(map));*/

/*        List<User> users = userDao.queryByParams(null, "白沐贞");
        for (User user : users) {
            System.out.println(user);
        }*/

        // userDao.insertUser(new User(4, "南笙", 18, "西域"));


        // userDao.deleteUser(4);

        // userDao.updateUser(new User(1, null, 16, null));
/*        Integer[] ids = {1, 2, 4};
        List<User> users = userDao.queryByIds(ids);
        for (User user : users) {
            System.out.println(user);*/

    }

    @Test
    public void orderDaoTest() {
        OrderDao orderDao = sqlSession.getMapper(OrderDao.class);
/*        List<Order> orders = orderDao.queryAll();
        for (Order order : orders) {
            System.out.println(order);
        }*/

        System.out.println(orderDao.queryById(2));
    }

    @After
    public void destroy() {
        // 提交事务
        sqlSession.commit();
        sqlSession.close();
    }

}
