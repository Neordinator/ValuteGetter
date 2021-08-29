#pragma once
#ifndef VALUTEDATA_H
#define VALUTEDATA_H

struct ValuteData {
    int nominal;
    double value;
    double course;
    double CourseConclusion(ValuteData &second) {
        return course / second.course;
    }
};

#endif