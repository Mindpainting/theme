table_first，table_second

table_second 中一列属性引用 table_first 中的主键，该属性为外键

- 新建 table_first，table_second 两个空表，先分别插入数据再添加外键约束关系，如果添加的所有数据中table_second 外键的值和 table_first 对应的值都相等，则外键关系建立成功；否则，失败。
- 先建立外键关系，只能先从 table_first 插入数据，table_second 外键的值和 table_first 中**存在**且对应的值**相等**时，table_second 才可以插入，否则，插入失败

- 只能先删除 table_second ，再删除 table_first
- 如果在 navcat 中设置如下两个值，则在 table_first 中的数据被修改时，table_second 中的外键值也会一起被修改

![image-20220320212128185](C:\Users\think\AppData\Roaming\Typora\typora-user-images\image-20220320212128185.png)