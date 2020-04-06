// Copyright 2020 Brazhnikov Eugene

#ifndef MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_
#define MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_

class MoneyConverter {
 public:
    double rubdollar(const double& curr, int  WhichOne) {
        if (curr >= 0 && WhichOne == 0) {  // RUB to EUR
            return curr / 77.73;
        } else if (curr >= 0 && WhichOne == 1) {  // EUR to RUB
            return curr * 77.73;
        } else {
            return -1;
        }
    }

    double rubeur(const double& curr, int WhichOne) {
        if (curr >= 0 && WhichOne == 0) {
            return curr / 85.73;
        } else if (curr >= 0 && WhichOne == 1) {
            return curr * 85.73;
        } else {
            return -1;
        }
    }

    double rubJPY(const double& curr, int WhichOne) {
        if (curr >= 0 && WhichOne == 0) {
            return curr / 71.40;
        } else if (curr >= 0 && WhichOne == 1) {
            return curr * 71.40;
        } else {
            return -1;
        }
    }

    double rubSEK(const double& curr, int WhichOne) {
        if (curr >= 0 && WhichOne == 0) {
            return curr / 78;
        } else if (curr >= 0 && WhichOne == 1) {
            return curr * 78;
        } else {
            return -1;
        }
    }

    double rubUAH(const double& curr, int WhichOne) {
        if (curr >= 0 && WhichOne == 0) {
            return curr / 2.79;
        } else if (curr >= 0 && WhichOne == 1) {
            return curr * 2.79;
        } else { return -1;
        }
    }
};

#endif  // MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_
