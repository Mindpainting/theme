package com.evjy.config;

import com.evjy.common.filter.JwtAuthenticationTokenFilter;
import com.evjy.service.impl.security.UserDetailsServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.ProviderManager;
import org.springframework.security.authentication.dao.DaoAuthenticationProvider;
import org.springframework.security.config.Customizer;
import org.springframework.security.config.annotation.authentication.configuration.EnableGlobalAuthentication;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityCustomizer;
import org.springframework.security.config.annotation.web.configurers.AbstractHttpConfigurer;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.web.AuthenticationEntryPoint;
import org.springframework.security.web.SecurityFilterChain;
import org.springframework.security.web.access.AccessDeniedHandler;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;
import org.springframework.web.cors.CorsConfiguration;
import org.springframework.web.cors.CorsConfigurationSource;
import org.springframework.web.cors.UrlBasedCorsConfigurationSource;

import java.util.Arrays;
import java.util.List;

/**
 * @Author Evjy
 * @Date 2024/3/15 16:17
 * @Description Spring Security 配置
 */

@Configuration
@EnableGlobalAuthentication
public class SecurityConfig {

    @Autowired
    UserDetailsServiceImpl userDetailsService;

    @Autowired
    JwtAuthenticationTokenFilter jwtAuthenticationTokenFilter;

    @Autowired
    AuthenticationEntryPoint authenticationEntryPoint;

    @Autowired
    AccessDeniedHandler accessDeniedHandler;

    @Bean
    SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
        http
            .authorizeHttpRequests(auth -> auth
                .requestMatchers("/user/login")
                // permitAll() 登录，未登录的用户都可访问
                // 请求允许匿名访问（未登录用户），登录之后的用户不能再访问
                .anonymous()
                // spring security6.2.3不再使用在配置类上添加@EnableGlobalMethodSecurity(prePostEnabled = true)，方法上使用@PreAuthorize("hasAnyAuthority('system:user:list')")来开启权限访问
                // 下面这样配置即可
                .requestMatchers("/user/sample").hasAnyAuthority("system:user:list")
                // 除上面配置的请求路径，其他路径的请求都需要认证
                .anyRequest().authenticated())
            .formLogin(form -> form.loginProcessingUrl("/login")
                .usernameParameter("username").passwordParameter("password"))
            .csrf(AbstractHttpConfigurer::disable)
            .sessionManagement(session -> session.maximumSessions(1).maxSessionsPreventsLogin(true));

        // 添加自定义过滤器
        http.addFilterBefore(jwtAuthenticationTokenFilter, UsernamePasswordAuthenticationFilter.class);

        // 配置自定义认证授权异常处理
        http.exceptionHandling(exceptionHandlingConfigurer ->
            exceptionHandlingConfigurer
                // 未认证异常处理
                .authenticationEntryPoint(authenticationEntryPoint)
                // 未授权访问异常处理
                .accessDeniedHandler(accessDeniedHandler)
        );

        // 允许跨域
        // by default uses a Bean by the name of corsConfigurationSource
        http.cors(Customizer.withDefaults());

        return http.build();
    }

    @Bean
    AuthenticationManager authenticationManager() {
        DaoAuthenticationProvider daoAuthenticationProvider = new DaoAuthenticationProvider();
        daoAuthenticationProvider.setUserDetailsService(userDetailsService);
        // 以Bean的形式注入BCryptPasswordEncoder报错，There is no PasswordEncoder mapped for the id "null"
        // 这里设置BCryptPasswordEncoder后解决问题
        daoAuthenticationProvider.setPasswordEncoder(new BCryptPasswordEncoder());
        return new ProviderManager(daoAuthenticationProvider);
    }

    // 注入容器，便于获取 BCryptPasswordEncoder 对象
    @Bean
    public PasswordEncoder passwordEncoder() {
        return new BCryptPasswordEncoder();
    }

//    @Bean
//    public WebSecurityCustomizer webSecurityCustomizer() {
//        return (web) -> web.ignoring().requestMatchers("/user/login");
//    }

    @Bean
    CorsConfigurationSource corsConfigurationSource() {
        CorsConfiguration corsConfiguration = new CorsConfiguration();

/*        corsConfiguration.setAllowedHeaders(List.of("Authorization", "Cache-Control", "Content-Type"));
        corsConfiguration.setAllowedOrigins(List.of("*"));
        corsConfiguration.setAllowedMethods(List.of("GET", "POST", "PUT", "DELETE", "PUT", "OPTIONS", "PATCH", "DELETE"));*/

        corsConfiguration.setAllowedHeaders(List.of("*"));
        corsConfiguration.setAllowedOrigins(List.of("*"));
        corsConfiguration.setAllowedMethods(List.of("*"));
        corsConfiguration.setAllowCredentials(true);
        corsConfiguration.setExposedHeaders(List.of("Authorization"));
        UrlBasedCorsConfigurationSource source = new UrlBasedCorsConfigurationSource();
        source.registerCorsConfiguration("/**", corsConfiguration);
        return source;
    }

}