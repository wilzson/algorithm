  #include <iostream>
  #include <cstring>
  using namespace std ;

  string a , b ;
  int ans = 1 , num = 1 ; //����Ҫע����ʼֵ����Ϊ1��Ҫ��0�Ļ����е����˳�������0��....

 int main(){
  	int n;
      cin >>n>> a >> b ; // ����
      for( int i = 0 ; i < a.length() ; i ++ ) ans *= a[i] - 'A'+1 ;
      // @�ı��Ϊ64 ��A�ı��65-@�ı��64����������Ӧ��Ӣ����ĸ�������...
      for( int i = 0 ; i < b.length() ; i ++ ) num *= b[i] - 'A'+1 ;
      // ͬ��
      ans %= n, num %= n; // �������⣬mod 47
      if( ans == num ) cout << "Attack!" ;
      else cout << "Stay" ; //���
      return 0 ; //��������
  }
