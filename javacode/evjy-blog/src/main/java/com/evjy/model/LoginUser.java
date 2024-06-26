package com.evjy.model;

import com.alibaba.fastjson2.JSONWriter;
import com.alibaba.fastjson2.annotation.JSONField;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;

import java.io.Serial;
import java.util.Collection;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * @Author Evjy
 * @Date 2024/3/15 15:43
 * @Description 保存登录用户详细信息的数据模型
 */

@Data
@NoArgsConstructor
@AllArgsConstructor
public class LoginUser implements UserDetails {

    @Serial
    private static final long serialVersionUID = 1L;

    /**
     * 用户唯一标识
     */
    private String token;

    /**
     * 登录时间
     */
    private Long loginTime;

    /**
     * 过期时间
     */
    private Long expires;

    /**
     * 登录 ip 地址
     */
    private String ipAddress;

    /**
     * 登录地点
     */
    private String loginLocation;

    /**
     * 浏览器类型
     */
    private String browser;

    /**
     * 操作系统
     */
    private String os;

    /**
     * 权限列表
     */
    @JSONField(serializeFeatures = JSONWriter.Feature.WriteMapNullValue)
    private Set<String> permissions;

    /**
     * 用户信息
     */
    // 参数为 null 也参与序列化
    @JSONField(serializeFeatures = JSONWriter.Feature.WriteMapNullValue)
    private AuthUser authUser;


    /**
     * 用户权限信息封装集合
     */
    // @JSONField(serialize = false)
    // private List<SimpleGrantedAuthority> authorities;
    public LoginUser(AuthUser authUser) {
        this.authUser = authUser;
    }

    public LoginUser(AuthUser authUser, Set<String> permissions) {
        this.authUser = authUser;
        this.permissions = permissions;
    }

    @JSONField(serialize = false)
    @Override
    public Collection<? extends GrantedAuthority> getAuthorities() {
        return permissions.stream().map(SimpleGrantedAuthority::new).collect(Collectors.toList());
    }

    @JSONField(serialize = false)
    @Override
    public String getPassword() {
        return authUser.getPassword();
    }

    @JSONField(serialize = false)
    @Override
    public String getUsername() {
        return authUser.getUserName();
    }

    @JSONField(serialize = false)
    @Override
    public boolean isAccountNonExpired() {
        return true;
    }

    @JSONField(serialize = false)
    @Override
    public boolean isAccountNonLocked() {
        return true;
    }

    @JSONField(serialize = false)
    @Override
    public boolean isCredentialsNonExpired() {
        return true;
    }

    /**
     * @description 用户是否可用
     */
    @JSONField(serialize = false)
    @Override
    public boolean isEnabled() {
        return true;
    }
}
