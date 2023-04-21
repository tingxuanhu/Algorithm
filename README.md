# Tips：
## 动态规划用到数组
- 在面对动态规划需要dp数组的时候，二维数组必须指定第二维的长度。你可以写成int dp[][k+1]，其中第一维可以自动推导出来，但这个用法不是标准用法，不是所有编译器都支持。更好的方式是使用指针来代替二维数组，这样就不需要在参数中指定第二维的长度了。
```cpp
    int **dp = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[k+1];
        memset(dp[i], -1, sizeof(int)*(k+1));
    }
```

## 常用的输入输出流总结：
- `cin >>` 负责吃string，碰到空格、回车、制表符则停止，缓存空间暂时保留下来，直到被使用或者再次吃新的数据
  - 如果能够知道一行元素的个数，可以用for loop来cin吃数据
 ```cpp
 for (int i = 0; i < N; ++i) { cin >> a[i] };
 ```

  - 如果不明确一行元素的个数，不能用cin来吃整行以空格为分隔的输入，而用std::istringstream
```cpp
int parentVal, leftVal, rightVal;
while (scanf("%d:%d|%d", &parentVal, &leftVal, &rightVal) == 3) {...}   // 用scanf可以处理连着输入但被： ｜等打断的情况，如果是空格，那istringstream就好
```

```cpp
如果想要在输入中使用空格或其他分隔符来分隔整数值，可以使用 `getline()` 函数读取一行字符串，然后使用 `istringstream` 类型的输入流来逐个读取其中的整数值。
对于输入描述中的示例输入，可以按照以下方式读取：
int main() {
    string line;
    getline(cin, line);  // 读取第一行输入的链表A的值
    istringstream iss(line);  // 将字符串转换成输入流
    int val;
    while (iss >> val) {  // 从输入流中读取整数
        cout << val << " ";
    }
    cout << endl;

    line.clear();
    getline(cin, line);  // 读取第二行输入的链表B的值
    iss.str(line);  // 清除 istringstream 对象之前的输入流，并将其替换为新字符串转换成的输入流
    iss.clear();   // iss.str(line) 将字符串 line 转成新输入流，并替换掉 istringstream 对象之前的输入流，但不会清除 istringstream 对象的状态和缓冲区，因此在使用 iss.str(line) 函数之前，需要先调用 iss.clear() 函数清除 istringstream 对象的状态和缓冲区。
    while (iss >> val) { 
        cout << val << " ";
    }
    cout << endl;

    return 0;
 在上述代码中，首先使用 `getline(cin, line)` 读取第一行输入的整数值，并将字符串转换成输入流 `istringstream`，然后逐个读取其中的整数值并输出。
 接着使用 `getline(cin, line)` 读取第二行输入的整数值，再将字符串转换成输入流 `istringstream`，并逐个读取其中的整数值并输出。
}




```

