  #include <iostream>
  #include <cstring>
  using namespace std ;

  string a , b ;
  int ans = 1 , num = 1 ; //这里要注意起始值必须为1，要是0的话所有的数乘出来都是0了....

 int main(){
  	int n;
      cin >>n>> a >> b ; // 输入
      for( int i = 0 ; i < a.length() ; i ++ ) ans *= a[i] - 'A'+1 ;
      // @的编号为64 ，A的编号65-@的编号64不就是所对应的英语字母序号了嘛...
      for( int i = 0 ; i < b.length() ; i ++ ) num *= b[i] - 'A'+1 ;
      // 同上
      ans %= n, num %= n; // 根据题意，mod 47
      if( ans == num ) cout << "Attack!" ;
      else cout << "Stay" ; //输出
      return 0 ; //完美结束
  }
