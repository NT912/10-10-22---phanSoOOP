/*
Bài tập 3.1: Xây dựng lớp phân số Phanso cho phép thực hiện các thao tác:
Khởi tạo mặc định phân số = 0.
Khởi tạo với tử và mẫu cho trước.
Khởi tạo từ giá trị nguyên cho trước.
Khởi tạo từ một phân số khác.
Nhập, xuất.
Lấy tử số, mẫu số.
Gán giá trị cho tử số, mẫu số.
Nghịch đảo, rút gọn.
Cộng, trừ, nhân, chia, so sánh với phân số khác.
*/

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

class PhanSo
{
private:
  int tu, mau;

public:
  PhanSo() {}
  PhanSo(int tu, int mau)
  {
    this->tu = tu;
    this->mau = mau;
  }

  void setTu(int tu)
  {
    this->tu = tu;
  }

  int getTu()
  {
    return this->tu;
  }

  void setMau(int mau)
  {
    this->mau = mau;
  }

  int getMau()
  {
    return this->mau;
  }

  void nhapPhanSo()
  {
    cout << "Nhap tu: ";
    cin >> this->tu;
    cout << "Nhap mau: ";
    cin >> this->mau;
  }

  void xuatPhanSo()
  {
    cout << this->tu << "/" << this->mau;
  }

  bool check()
  {
    if (this->tu == 0 || this->mau == 0)
    {
      return false;
    }
    return true;
  }

  PhanSo nghichDao(PhanSo a)
  {
    PhanSo b;
    b.tu = a.mau;
    b.mau = a.tu;
    return b;
  }

  void rutGon()
  {
    int rg = abs(gcd(abs(this->tu), abs(this->mau)));
    this->tu = this->tu / rg;
    this->mau = this->mau / rg;
  }

  void quyDong(PhanSo &a)
  {
    this->rutGon();
    a.rutGon();

    this->tu = this->tu * a.mau;
    a.tu = a.tu * this->mau;

    this->mau = a.mau = this->mau * a.mau;
  }

  PhanSo congPhanSo(PhanSo a)
  {
    this->quyDong(a);
    PhanSo b;

    b.tu = this->tu + a.tu;
    b.mau = this->mau;
    b.rutGon();

    return b;
  }

  PhanSo truPhanSo(PhanSo a)
  {
    this->quyDong(a);
    PhanSo b;

    b.tu = this->tu - a.tu;
    b.mau = this->mau;
    b.rutGon();

    return b;
  }

  PhanSo nhanPhanSo(PhanSo a)
  {
    PhanSo b;

    b.tu = this->tu * a.tu;
    b.mau = this->mau * a.mau;
    b.rutGon();

    return b;
  }

  PhanSo chiaPhanSo(PhanSo a)
  {
    PhanSo b;

    b.tu = this->tu + a.mau;
    b.mau = this->mau + a.tu;
    b.rutGon();

    return b;
  }

  void soSanh(PhanSo a)
  {
    this->rutGon();

    if (this->tu > a.tu)
    {
      cout << "Phan so " << this->tu << "/" << this->mau << " > Phan so ";
      a.xuatPhanSo();
    }
    else if (this->tu < a.tu)
    {
      cout << "Phan so " << this->tu << "/" << this->mau << " < Phan so ";
      a.xuatPhanSo();
    }
    else if (this->tu == a.tu)
    {
      cout << "Phan so " << this->tu << "/" << this->mau << " = Phan so ";
      a.xuatPhanSo();
    }
  }

  void soSanhPhanSo(PhanSo a)
  {
    if (a.mau != this->mau)
    {
      this->rutGon();
      a.rutGon();
      this->quyDong(a);

      soSanh(a);
    }
    else
    {
      soSanh(a);
    }
  }
};

int main()
{
  PhanSo A(0, 0);
  PhanSo B(90, 100);
  PhanSo C;
  PhanSo D = B;

  cout << "Nhap phan so C\n";
  C.nhapPhanSo();

  cout << "Phan so A: ";
  A.xuatPhanSo();
  cout << "\nPhan so B: ";
  B.xuatPhanSo();
  cout << "\nPhan so C: ";
  C.xuatPhanSo();
  cout << "\nPhan so D: ";
  D.xuatPhanSo();

  if (C.check() == false)
  {
    cout << "\nPhan so A khong hop le";
    return 0;
  }

  if (B.check() == false)
  {
    cout << "\nPhan so B khong hop le";
    return 0;
  }

  if (C.check() == false)
  {
    cout << "\nPhan so C khong hop le";
    return 0;
  }

  if (D.check() == false)
  {
    cout << "\nPhan so D khong hop le";
    return 0;
  }

  cout << "\n-------------RUT GON PHAN SO-------\n";
  cout << "Phan so A: ";
  A.rutGon();
  A.xuatPhanSo();
  cout << "\nPhan so B: ";
  B.rutGon();
  B.xuatPhanSo();
  cout << "\nPhan so C: ";
  C.rutGon();
  C.xuatPhanSo();
  cout << "\nPhan so D: ";
  D.rutGon();
  D.xuatPhanSo();

  cout << "\n-------------CONG HAI PHAN SO-------\n";
  cout << "Tong phan so: ";
  PhanSo tong = C.congPhanSo(B);
  tong.xuatPhanSo();

  cout << "\n-------------TRU HAI PHAN SO-------\n";
  cout << "hieu phan so: ";
  PhanSo hieu = C.truPhanSo(B);
  hieu.xuatPhanSo();

  cout << "\n-------------NHAN HAI PHAN SO-------\n";
  cout << "Tong phan so: ";
  PhanSo tich = C.nhanPhanSo(B);
  tich.xuatPhanSo();

  cout << "\n-------------CHIA HAI PHAN SO-------\n";
  cout << "Tong phan so: ";
  PhanSo thuong = C.chiaPhanSo(B);
  thuong.xuatPhanSo();

  cout << "\n-------------SO SANH HAI PHAN SO-------\n";
  C.soSanh(B);

  return 0;
}