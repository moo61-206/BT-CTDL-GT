#include <iostream>
#include <string>
using namespace std;
struct SV {
    string HoTen;
    string MSSV;
    int NamSinh;
    float GPA;
    SV* next;
};
struct DSSV {
    SV* firstSV;
};
void initialize(DSSV& DS) {
    DS.firstSV = nullptr;
}
SV* SV_moi(string hoTen, string mssv, int namSinh, float gpa) {
    SV* newSV = new SV;
    newSV->HoTen = hoTen;
    newSV->MSSV = mssv; 
    newSV->NamSinh = namSinh;
    newSV->GPA = gpa;
    newSV->next = nullptr;
    return newSV;
}
void them_SV(DSSV& DS, SV* newSV) {
    newSV->next = DS.firstSV;
    DS.firstSV = newSV;
}
void swapSVData(SV* a, SV* b) {
    string tempHoTen = a->HoTen; a->HoTen = b->HoTen; b->HoTen = tempHoTen;
    string tempMSSV = a->MSSV; a->MSSV = b->MSSV; b->MSSV = tempMSSV;
    int tempNamSinh = a->NamSinh; a->NamSinh = b->NamSinh; b->NamSinh = tempNamSinh;
    float tempGPA = a->GPA; a->GPA = b->GPA; b->GPA = tempGPA;
}
int DSSV_dai(DSSV DS) {
    int k = 0;
    SV* t = DS.firstSV;
    while (t != nullptr) {
        k++;
        t = t->next;
    }
    return k;
}
void SV_in_ra(DSSV DS) {
    int k = DSSV_dai(DS);
    cout << "\nDANH SACH (Tong so: " << k << " SV)" << endl;
    if (DS.firstSV == nullptr) {
        cout << "DANH SACH RONG" << endl;
    }
    else {
        SV* t = DS.firstSV;
        int index = 1;
        while (t != nullptr) {
            cout << index << ". " << t->HoTen << " | MSSV: " << t->MSSV
                << " | Nam Sinh: " << t->NamSinh << " | **GPA: " << t->GPA << "**" << endl;
            t = t->next;
            index++;
        }
    }
    cout << endl;
}
int gpa_hon_3_2(DSSV DS) {
    int k = 0;
    SV* t = DS.firstSV;
    while (t != nullptr) {
        if (t->GPA > 3.2f) {
            k++;
        }
        t = t->next;
    }
    return k;
}
void sap_xep_theo_gpa(DSSV& DS) {
    if (DS.firstSV == nullptr || DS.firstSV->next == nullptr) {
        return;
    }
    SV* t = DS.firstSV;
    while (t != nullptr) {
        SV* min_gpa = t;
        SV* next_node = t->next;
        while (next_node != nullptr) {
            if (next_node->GPA < min_gpa->GPA) {
                min_gpa = next_node;
            }
            next_node = next_node->next;
        }
        if (min_gpa != t) {
            swapSVData(t, min_gpa);
        }
        t = t->next;
    }
}
void chen_SV(DSSV& DS, SV* newSV) {
    if (DS.firstSV == nullptr || newSV->GPA < DS.firstSV->GPA) {
        newSV->next = DS.firstSV;
        DS.firstSV = newSV;
        return;
    }
    SV* t = DS.firstSV;
    while (t->next != nullptr && t->next->GPA < newSV->GPA) {
        t = t->next;
    }
    newSV->next = t->next;
    t->next = newSV;
}
int main() {
    DSSV DanhSachSV;
    initialize(DanhSachSV);
    them_SV(DanhSachSV, SV_moi("Nguyen Van A", "202414139", 2006, 2.2f));
    them_SV(DanhSachSV, SV_moi("Tran Van B", "202415432", 2006, 2.9f));
    them_SV(DanhSachSV, SV_moi("Le Thi C", "20221435", 2004, 3.9f));
    them_SV(DanhSachSV, SV_moi("Pham Thi D", "202511528", 2007, 1.8f));
    them_SV(DanhSachSV, SV_moi("Hoang Nam E", "202512345", 2007, 3.3f));
    SV_in_ra(DanhSachSV);
    cout << "=> Chieu dai cua danh sach: " << DSSV_dai(DanhSachSV) << endl;
    cout << "=> So luong sinh vien GPA > 3.2: " << gpa_hon_3_2(DanhSachSV) << endl;
    sap_xep_theo_gpa(DanhSachSV);
    SV* sv_gpa_2_4 = SV_moi("Nguyen Nhat F", "20231542", 2005, 2.4f);
    chen_SV(DanhSachSV, sv_gpa_2_4);
    SV_in_ra(DanhSachSV);
    return 0;
}