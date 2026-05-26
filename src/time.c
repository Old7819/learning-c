#include <stdio.h>
#include <assert.h>

// Объявляем новый тип данных struct Time:
struct Time {
    int h;
    int m;
};    

void print_time(struct Time t); // hh:mm

int time2min(struct Time t);    // h, m -> mm 0:00
struct Time min2time(int mm);   // mm -> h, m
struct Time add(struct Time t1, struct Time dt);

int is_equal(struct Time t1, struct Time t2);

int main()
{
    struct Time t1 = {22, 55},
                dt = {2, 7},
                t2,
                exp_t2 = {1, 2};
                
    print_time(t1); // 22:55
    print_time(dt); // 02:07
    
    assert(time2min(dt) == 127);
    assert(1==is_equal(min2time(127), dt));    // ???
    
    t2 = add(t1, dt);
    print_time(t2);

    assert(1==is_equal(t2, exp_t2)); 
    
    return 0;
}

struct Time add(struct Time t1, struct Time dt)
{
    int mm = time2min(t1) + time2min(dt);
    struct Time res;
    res = min2time(mm);
    return res;
    // return min2time(time2min(t1) + time2min(dt));
}

int is_equal(struct Time t1, struct Time t2)
{
    if (t1.h != t2.h)
        return 0;
    if (t1.m != t2.m)
        return 0;
    return 1;
    // return t1.h == t2.h && t1.m == t2.m;
}

// mm -> h, m
struct Time min2time(int mm)
{
    struct Time res;
    res.m = mm % 60;
    res.h = mm / 60 % 24;
    return res;
}

// h, m -> mm 0:00
int time2min(struct Time t)
{
    int res;
    res = t.h * 60 + t.m;
    return res;
}

void print_time(struct Time t)
{
    printf("%02d:%02d\n", t.h, t.m);
}