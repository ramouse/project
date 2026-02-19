### 定义和特性

在 C++ 中，`<map>` 是标准模板库（STL）的一部分，它提供了一种关联容器，用于存储键值对（key-value pairs）。

`map` 容器中的元素是按照键的顺序自动排序的，这使得它非常适合需要快速查找和有序数据的场景。

###### 特性

- `map` 存储的是键值对，其中每个键都是唯一的。
- `map` 中的元素按照键的顺序自动排序，通常是升序。
- 每个键在 `map` 中只能出现一次。
- `map` 提供了双向迭代器(iterators)，可以向前和向后遍历元素。



### 基本使用

1. 语法：

   - 头文件：`` #include<map>`` 

   - 声明：``std::map<key_type，value_type> myMap  ``  ``//可声明多维map，例如:std::map<int,map<int,int>> myMap`` 

   - 插入元素:``myMap[key] = value;``  `多维map的插入:myMap[key_1][key_2] = value;`

   - 访问元素：`value = myMap[key];`

     - `myMap[key]; //返回key对应的值 `    `多维map的访问:myMap[key_1][key_2];`

   - 遍历:

     ```c++
     //常规遍历
     for(std::map<key_type,value_type>::iterator it = myMap.begin(); it != myMap.end();++it){
     	std::cout<<it->first<<" "<<it->second<<std::endl;
     }
     
     
     
     //简化遍历
     for (auto &p : m) {
         std::cout << p.first << " : " << p.second << std::endl;
     }
     
     //示例：
     #include<bits/stdc++.h>
     using namespace std;
     
     int main() {
     	map<int, int> mymap;
     	for (int i = 0; i < 10; i++) {
     		mymap[i] = i;
     	}
     
     	for (auto& p : mymap) {
     		cout << p.first << " : " << p.second << endl;
     	}
     
     	return 0;
     }
     ```

     

   -  删除元素:`myMap.erase(key);`

   - 清空map:`myMap.clear();`

   - 获取map大小：`myMap.size();`

   - 检查存在:`myMap.count("Bob"); // key 是否存在（返回 0 或 1）`

   - 检查键存在:
   
     ```
     if (myMap.find(key) != myMap.end()) {
         // 键存在
     }
     ```
     
   - 其他方法:`myMap.clear();`

###经典例题

[寄包柜  ](https://www.luogu.com.cn/problem/P3613?contestId=283740)   [深基17.例6学籍管理 - 洛谷](https://www.luogu.com.cn/problem/P5266?contestId=283740)

