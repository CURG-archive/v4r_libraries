/***************************************************************************
 *   Copyright (C) 2010 by Markus Bader                                    *
 *   markus.bader@tuwien.ac.at                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
/**
 * @file timehdl.hpp
 * @author Markus Bader
 * @brief
 **/

#ifndef V4RTIMEHDL_H
#define V4RTIMEHDL_H

#include <sys/time.h>
#include <boost/thread/xtime.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


namespace V4R {

/**
 * class to manage loop frequenses
 **/
class FQSleep {
public:
    FQSleep(const double &rFrequenz);
		void set(const double &rFrequenz);
    void wait();
private:
	  double mrFrequenz;
    boost::xtime mXTime;
    boost::xtime mPriod;
};

/**
 * class to manage timings
 **/
class Timer {
public:
    Timer() {};
    boost::posix_time::ptime  &start(const std::string &rName);
    boost::posix_time::time_duration &stop(const std::string &rName);
    boost::posix_time::time_duration &operator[](const std::string &rName) {
        return get(rName);
    }    
    boost::posix_time::time_duration &get(const std::string &rName) {
        return mDuration[rName];
    }
    long ms(const std::string &rName);
private:
    std::map< std::string, boost::posix_time::ptime > mStartTime;
    std::map< std::string, boost::posix_time::time_duration > mDuration;
};
/**
 * timeval to local ptime
 * @param sec
 * @param usec milliseconds
 * @param nsec nanoseconds
 * @return ptime
 **/
boost::posix_time::ptime  timeval2ptime_utc(unsigned long sec, unsigned long  usec, unsigned long  nsec = 0);
/**
 * timeval to local ptime
 * @param t
 * @return ptime
 **/
boost::posix_time::ptime  timeval2ptime_utc(const timeval &t);
/**
 * timeval to local ptime
 * This local adjustor depends on the machine TZ settings-- highly dangerous!
 * @param sec
 * @param usec milliseconds
 * @param nsec nanoseconds
 * @return ptime
 **/
boost::posix_time::ptime  timeval2ptime_local(unsigned long sec, unsigned long usec, unsigned long  nsec = 0);
/**
 * timeval to local ptime
 * This local adjustor depends on the machine TZ settings-- highly dangerous!
 * @param t
 * @return ptime
 **/
boost::posix_time::ptime  timeval2ptime_local(const timeval &t);
void sleepMs ( unsigned int ms );
};

#endif
