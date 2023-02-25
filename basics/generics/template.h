//
// Created by adren on 9/16/2017.
//

#ifndef CPP_TEMPLATE_H
#define CPP_TEMPLATE_H

template<typename T>
class Operations {
public:
    T findMax(int first, int second) {
        return first > second ? first : second;
    }
    T findMin(int first, int second) {
        return first < second ? first : second;
    }
};

#endif //CPP_TEMPLATE_H
