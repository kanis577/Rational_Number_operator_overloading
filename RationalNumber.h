#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H
#include <cstdlib>
#include <iostream>
using namespace std;

class RationalNumber
{
    public:
        RationalNumber();
        RationalNumber(int,int);
        void printRational();
        void reduction();
    RationalNumber operator +(RationalNumber &);
    RationalNumber operator -(RationalNumber &);
    RationalNumber operator *(RationalNumber &);
    RationalNumber operator /(RationalNumber &);
    friend bool operator>(const RationalNumber &r1,const RationalNumber &r2)
    {
         if(r1.denominator_==r2.denominator_)
        {
            if(r1.numerator_>r2.numerator_)return true;
            else return false;
        }
        else
        {
            RationalNumber r3;
            RationalNumber r4;



            r3.denominator_=r1.denominator_*r2.denominator_;
            r4.denominator_=r2.denominator_*r1.denominator_;

            r3.numerator_=r1.numerator_*r2.denominator_;
            r4.numerator_=r2.numerator_*r1.denominator_;

            if(r3.numerator_>r4.numerator_)return true;
            else return false;

        }
    }
    friend bool operator==(const RationalNumber &r1,const RationalNumber &r2)
    {
         if((r1.numerator_==r2.numerator_&&r1.denominator_==r2.denominator_))
        {
            return true;
        }
        else return false;
    }
    friend bool operator >=(const RationalNumber &r1,const RationalNumber &r2)
    {
        if(r1.denominator_==r2.denominator_)
        {
            if(r1.numerator_>=r2.numerator_)return true;
            else return false;
        }
        else
        {
            RationalNumber r3;
            RationalNumber r4;


            r3.denominator_=r1.denominator_*r2.denominator_;
            r4.denominator_=r2.denominator_*r1.denominator_;

            r3.numerator_=r1.numerator_*r2.denominator_;
            r4.numerator_=r2.numerator_*r1.denominator_;

            if(r3.numerator_>=r4.numerator_)return true;
            else return false;

    }
    }
        private:
        int numerator_,denominator_;
};
RationalNumber::RationalNumber()
{
    this->numerator_=0;
    this->denominator_=0;
}
RationalNumber::RationalNumber(int a_,int b_)
{
    this->numerator_=a_;
    this->denominator_=b_;
    if(this->numerator_==this->denominator_)
    {
        this->numerator_=this->numerator_/this->denominator_;
        this->denominator_=1;
    }
    else reduction();
}
void RationalNumber ::reduction()
{
    if(this->denominator_==this->numerator_)
    {
        denominator_=1;
        numerator_=1;
        return;
    }
    else if(denominator_==-numerator_)
    {
        numerator_=-1;
        denominator_=1;
        return;
    }
    else
    {
        int max_;
        if(numerator_>denominator_)max_=numerator_;
        else max_=denominator_;
            for(int i=2;i<=max_/2;i++)
            {
                if(numerator_%i==0&&denominator_%i==0)
                {
                    numerator_/=i;denominator_/=i;
                }
            }
    }

}
RationalNumber RationalNumber::operator+(RationalNumber &r1)
{
    RationalNumber r3;
    if(this->denominator_==r1.denominator_)
    {
        r3.numerator_=this->numerator_+r1.numerator_;
        r3.denominator_=r1.denominator_;
    }
    else
    {
        r3.numerator_=(this->numerator_*r1.denominator_)+(this->denominator_*r1.numerator_);
        r3.denominator_=this->denominator_*r1.denominator_;
    }
    return r3;
}
RationalNumber RationalNumber::operator-(RationalNumber &r1)
{
    RationalNumber r3;
    if(this->denominator_==r1.denominator_)
    {
        r3.numerator_=this->numerator_-r1.numerator_;
        r3.denominator_=r1.denominator_;
    }
    else
    {
        r3.denominator_=this->denominator_*r1.denominator_;
        r3.numerator_=(this->numerator_*r1.denominator_)-(r1.numerator_*this->denominator_);
    }
    return r3;
}
RationalNumber RationalNumber::operator*(RationalNumber &r1)
{
    RationalNumber r3;
    r3.denominator_=this->denominator_*r1.denominator_;
    r3.numerator_=this->numerator_*r1.numerator_;
    return r3;
}
RationalNumber RationalNumber::operator/(RationalNumber &r1)
{
    RationalNumber r3;
    r3.denominator_=this->denominator_*r1.numerator_;
    r3.numerator_=this->numerator_*r1.denominator_;
    return r3;
}
void RationalNumber::printRational()
{
        reduction();
        if(denominator_==1)cout<<numerator_;
        else if(numerator_==0)cout<<0;
        else cout<<numerator_<<"/"<<denominator_;
}
#endif
