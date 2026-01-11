#include <stdio.h>
#include <vector>

int &getMaxVal(std::vector<int> &vecTest){
    int maxId = 0;
    for (int i = 0; i < vecTest.size(); i++){
        if (vecTest[i] > vecTest[maxId]) maxId = i;
    }
    return vecTest[maxId];
}

int main(){
    
    std::vector<int> vecTest = {10, 11, 12, 13, 14, 15};
    
    int &val = getMaxVal(vecTest);
    
    printf("%d\n", val);

    for (int it : vecTest) printf("%d , ", it);
    printf("\n");
    
    val = 20;

    for (int it : vecTest) printf("%d , ", it);

    printf("\n");
    return 0;
}
