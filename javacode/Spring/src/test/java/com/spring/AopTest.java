package com.spring;

import com.spring.aop.Calculate;
import com.spring.aop.CalculateImpl;
import com.spring.aop.MyInvocationHandler;
import org.junit.Test;

public class AopTest {
    @Test
    public void test() {
        CalculateImpl calculate = new CalculateImpl();
        MyInvocationHandler myInvocationHandler = new MyInvocationHandler();
        Calculate cal = (Calculate) myInvocationHandler.bind(calculate);
        cal.add(3, 2);
        cal.sub(3, 2);
        cal.mul(3, 2);
        cal.div(3, 2);
    }
}
