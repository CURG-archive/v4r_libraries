/**
 * @file structs_clic.h
 * @author Markus Bader
 * @brief
 *
 * @see
 **/

#ifndef V4R_STRUCTS_CLIC_H
#define V4R_STRUCTS_CLIC_H

#include <iostream>
#include <iomanip>
#include <stdint.h>

#ifndef INT16_MAX
#define INT16_MAX 0x7fff
#endif
#ifndef INT16_MIN
#define INT16_MIN (-INT16_MAX - 1)
#endif
#ifndef M_PI
#define M_PI    3.14159265358979323846f
#endif
namespace CLIC {

class IO_Obstacle;


/**
 * Clic UDP data header
 * @author Markus Bader
 **/
class IO_Header {
public:
    /// Constructor
    IO_Header()
            : mVersion(0)
            , mNrOfObj(0)
            , mScene(0)
            , mReserved(0) {}
    /** Constructor
    	 * @param r data to encode
    	 */
    IO_Header(const IO_Header &r)
            : mVersion(r.mVersion)
            , mNrOfObj(r.mNrOfObj)
            , mScene(r.mScene)
            , mReserved(r.mReserved) {}
    /** Constructor
    	 * @param version
    	 * @param nrOfObj
    	 * @param scene
    	 * @param reserverd
    	 */
    IO_Header(unsigned int version, unsigned int nrOfObj, unsigned int scene, unsigned reserverd = 0)
            : mVersion(version)
            , mNrOfObj(nrOfObj)
            , mScene(scene)
            , mReserved(reserverd) {

    }
    /// @return number of Objects
    unsigned int nrOfObj() const {
        return mNrOfObj;
    }
    void set(unsigned int version, unsigned int nrOfObj, unsigned int scene, unsigned reserverd = 0) {
        mVersion = version, mNrOfObj = nrOfObj, mScene = scene, mReserved = reserverd;
    }
    /// @return version
    unsigned int version() const {
        return mVersion;
    }
    /// @return scene
    unsigned int scene() const {
        return mScene;
    }
    /// Outputfunction
    friend std::ostream& operator << ( std::ostream &os, const CLIC::IO_Header &r) {
        os << "version = " << r.version();
        os << ", objects = " << r.nrOfObj();
        os << ", scene = " << r.scene();
        return os;
    };
private:
    uint8_t mVersion; /// version
    uint8_t mNrOfObj; /// number of Objects
    uint8_t mScene;   /// Sence
    uint8_t mReserved;/// Reserved
};

/**
 * Clic UDP Angle encoding
 * @author Markus Bader
 **/
class IO_Angle {
    friend class IO_Obstacle;
public:
    /// Constructor
    IO_Angle() : mVal(0) {}
    /** Copy constructor
    	 * @param r
    	 */
    IO_Angle(const IO_Angle &r) : mVal(r.mVal) {};
    /** constructor
    	 * @param val data to encode
    	 */
    IO_Angle(double val) : mVal(0) {
        set(val);
    };
    /** set round((val * (double) INT16_MAX) / M_PI)
    	 * @param val data to encode
    	 * @return true on error
    	 */
    bool set(double val) {
        mVal = round((val * (double) INT16_MAX) / M_PI);
        if ((val > M_PI) || (val < -M_PI)) {
            std::cerr << "ERROR: IO_Angle::set value out of range [pi, -pi]: ";
            std::cerr << val << " rad" << std::endl;
            return 1;
        }
        return 0;
    }
    /** set
    	 * @param val data to copy
    	 */
    void set(const IO_Angle &val) {
        mVal = val.mVal;
    }
    /** get (mVal * M_PI) / (double) INT16_MAX;
    	 * @return encoded data
    	 */
    double get() const {
        return (mVal * M_PI) / (double) INT16_MAX;
    }
    /** a quick version of get
    	 * @return encoded data
    	 */
    double operator ()() const {
        return get();
    }
    /** a quick version of set
    	 * @param val data to encode
    	 * @return true on error
    	 */
    bool operator = (const double &val) {
        return set(val);
    }
    /** a quick version of set
    	 * @param val data to copy
    	 */
    void operator = (const IO_Angle &val) {
        set(val);
    }
    /** decodes a string to a double
    	 * @param ss data to encode as string
    	 * @return true on error
    	 */
    bool operator << (std::stringstream &ss) {
        double d;
        ss >> d;
        return set(d);
    }
    /** normalized a angle value to be between -pi and pi
    	 * @param v input angle (rad)
    	 * @return normalized angle (rad)
    	 */
    static const double normalize(double v) {
        while (v > M_PI) v -= (2.0*M_PI);
        while (v < -M_PI) v += (2.0*M_PI);
        return v;
    }


private:
    int16_t mVal; /// Data encoded as little endian
};

/**
 * Clic UDP Rotation Axis encoding
 * @author Markus Bader
 **/
class IO_Axis {
    friend class IO_Obstacle;
public:
    /// Constructor
    IO_Axis() : mVal(0) {}
    /** Copy constructor
    	 * @param r
    	 */
    IO_Axis(const IO_Axis &r) : mVal(r.mVal) {};
    /** constructor
    	 * @param val data to encode
    	 */
    IO_Axis(double val) : mVal(0) {
        set(val);
    };
    /** set round(val * (double) INT16_MAX)
    	 * @param val data to encode
    	 * @return true on error
    	 */
    bool set(double val) {
        mVal = round(val * (double) INT16_MAX);
        if ((val > 1.0) || (val < -1.0)) {
            std::cerr << "ERROR: IO_Axis::set value out of range [1.0, -1.0]: ";
            std::cerr << val << std::endl;
            return 1;
        }
        return 0;
    }
    /** set
    	 * @param val data to copy
    	 */
    void set(const IO_Axis &val) {
        mVal = val.mVal;
    }
    /** get mVal / (double) INT16_MAX;
    	 * @return encoded data
    	 */
    double get() const {
        return mVal / (double) INT16_MAX;
    }
    /** a quick version of get
    	 * @return encoded data
    	 */
    double operator ()() const {
        return get();
    }
    /** a quick version of set
    	 * @param val data to encode
    	 * @return true on error
    	 */
    bool operator = (const double &val) {
        return set(val);
    }
    /** a quick version of set
    	 * @param val data to copy
    	 */
    void operator = (const IO_Axis &val) {
        set(val);
    }
    /** decodes a string to a double
    	 * @param ss data to encode as string
    	 * @return true on error
    	 */
    bool operator << (std::stringstream &ss) {
        double d = 0;
        ss >> d;
        return set(d);
    }
    ///Outputfunction
    friend std::ostream& operator << ( std::ostream &os, const CLIC::IO_Axis &r) {
        return os << r();
    };
private:
    int16_t mVal; /// Data encoded as little endian
};

/**
 * Clic UDP Distance to the origion encoding
 * @author Markus Bader
 **/
class IO_Distance {
    friend class IO_Obstacle;
public:
    /// Constructor
    IO_Distance() : mVal(0) {}
    /** Copy constructor
    	 * @param r
    	 */
    IO_Distance(const IO_Distance &r) : mVal(r.mVal) {};
    /** constructor
    	 * @param val data to encode
    	 */
    IO_Distance(double val) : mVal(0) {
        set(val);
    };
    /** set round(val * 1000.0)
    	 * @param val data to encode
    	 * @return true on error
    	 */
    bool set(double val) {
        double millimeters = val * 1000.0;
        mVal = round(millimeters);
        if ((millimeters >= INT16_MAX) || (millimeters <= INT16_MIN)) {
            std::cerr << "ERROR: IO_Distance::set out of range [ 32.768, -32.768]: ";
            std::cerr << val << " m" << std::endl;
            return 1;
        }
        return 0;
    }
    /** set
    	 * @param val data to copy
    	 */
    void set(const IO_Distance &val) {
        mVal = val.mVal;
    }
    /** get mVal / 1000.0;
    	 * @return encoded data
    	 */
    double get() const {
        return mVal / 1000.0;
    }
    /** a quick version of get
    	 * @return encoded data
    	 */
    double operator ()() const {
        return get();
    }
    /** a quick version of set
    	 * @param val data to encode
    	 * @return true on error
    	 */
    bool operator = (const double &val) {
        return set(val);
    }
    /** a quick version of set
    	 * @param val data to copy
    	 */
    void operator = (const IO_Distance &val) {
        set(val);
    }
    /** decodes a string to a double
    	 * @param ss data to encode as string
    	 * @return true on error
    	 */
    bool operator << (std::stringstream &ss) {
        double d = 0;
        ss >> d;
        return set(d);
    }
private:
    int16_t mVal;
};

typedef IO_Distance IO_Velocity;


/**
 * Clic UDP Obstacle type
 * @author Markus Bader
 **/
class IO_Type {
    friend class IO_Obstacle;
public:
    /// Constructor
    IO_Type() : mVal(0) {}
    /** Copy constructor
    	 * @param r
    	 */
    IO_Type(const IO_Type &r) : mVal(r.mVal) {};
    /** constructor
    	 * @param val data to encode
    	 */
    IO_Type(unsigned int val) : mVal(0) {
        set(val);
    };
    /** set
    	 * @param val
    	 */
    void set(uint8_t type) {
        mVal = type;
    }
    /** set
    	 * @param val data to copy
    	 */
    void set(const IO_Type &val) {
        mVal = val.mVal;
    }
    /** get
    	 * @return type
    	 */
    unsigned int get() const {
        return mVal;
    }
    /** get
    	* @return type
    	*/
    unsigned int getShape() const {
        return (mVal >> 2) & 0x03;
    }
    /** get
    	* @return type
    	*/
    unsigned int getColor() const {
        return (mVal & 0x03);
    }
    /** setColor
    	* @return type
    	*/
    void setColor(uint8_t c) {
        mVal = (mVal & 0xF7) | (0x03 & c);
    }
    /** setShape
    	* @return type
    	*/
    void setShape(uint8_t s) {
        mVal = (mVal & 0xF3) | ((0x03 & s) << 2);
    }
    /** a quick version of get
    	 * @return type
    	 */
    unsigned int operator ()() const {
        return get();
    }

    /** a quick version of set
    	 * @param val
    	 */
    void operator = (unsigned int &val) {
        set(val);
    }
    /** a quick version of set
    	 * @param val data to copy
    	 */
    void operator = (const IO_Type &val) {
        return set(val);
    }
    /** decodes a string to a int
    	 * @param ss data to encode as string
    	 * @todo check if the string contains useful data
    	 */
    void operator << (std::stringstream &ss) {
        int d = 0;
        ss >> d;
        setShape((uint8_t) d);
        ss >> d;
        setColor((uint8_t) d);
    }
    /// Outputfunction
    friend std::ostream& operator << ( std::ostream &os, const CLIC::IO_Type &r) {
        return os << "shape: " << r.getShape() << " color: " << r.getColor();
    };

private:
    uint8_t mVal;
};

/**
 * Clic UDP Obstacle package
 * @author Markus Bader
 **/
class IO_Obstacle {
public:
    /// Constructor
    IO_Obstacle() {};
    /** Copy constructor
    	 * @param r
    	 */
    IO_Obstacle(const std::string &str) {
        (*this) << str;
    };
    /** Copy constructor
    	 * @param r
    	 */
    IO_Obstacle(const IO_Obstacle &r) {
        memcpy(mData, r.mData, sizeof(IO_Obstacle));
    }
    void operator << ( const std::string &str) {
        memset(mData, 0, sizeof(IO_Obstacle));
        std::stringstream ss(str);
        int i = 0;
        double d = 0;
        ss >> i;
        id(i);
        ss >> d;
        kx(d);
        ss >> d;
        ky(d);
        ss >> d;
        kz(d);
        ss >> d;
        phi(d);
        ss >> d;
        dx(d);
        ss >> d;
        dy(d);
        ss >> d;
        dz(d);
        ss >> d;
        vx(d);
        ss >> d;
        vy(d);
        ss >> d;
        vz(d);
        ss >> i;
        shape(i);
        ss >> i;
        color(i);
        ss >> d;
        lx(d);
        ss >> d;
        ly(d);
        ss >> d;
        lz(d);
    }
    /// Outputfunction
    friend std::ostream& operator << ( std::ostream &os, const CLIC::IO_Obstacle &r) {
        os << "id = " << (int) r.id();
        os << std::setprecision (3) << std::fixed  << ", k = [" << r.kx() << " " << r.ky() << " " << r.kz() << "]";
        os << std::setprecision (3) << std::fixed  << ", phi = " << r.phi();
        os << std::setprecision (3) << std::fixed  << ", d = [" << r.dx() << " " << r.dy() << " " << r.dz() << "]";
        os << std::setprecision (3) << std::fixed  << ", v = [" << r.vx() << " " << r.vy() << " " << r.vz() << "]";
        os << ", shape: " << r.shape() << " color: " << r.color();
        os << std::setprecision (3) << std::fixed  <<  ", l = [" << r.lx() << " " << r.ly() << " " << r.lz() << "]";
        return os;
    };
    unsigned int id() const {
        return  mData[0];
    }
    void id(unsigned int v) {
        mData[0] = v;
    }
    double kx() const {
        return ((IO_Axis &) mData[1]).get();
    }
    void kx(double v) {
        ((IO_Axis &) mData[1]).set(v);
    }
    double ky() const {
        return ((IO_Axis &) mData[3]).get();
    }
    void ky(double v) {
        ((IO_Axis &) mData[3]).set(v);
    }
    double kz() const {
        return ((IO_Axis &) mData[5]).get();
    }
    void kz(double v) {
        ((IO_Axis &) mData[5]).set(v);
    }
    double phi() const {
        return ((IO_Angle &) mData[7]).get();
    }
    void phi(double v) {
        ((IO_Angle &) mData[7]).set(v);
    }
    double dx() const {
        return ((IO_Distance &) mData[9]).get();
    }
    void dx(double v) {
        ((IO_Distance &) mData[9]).set(v);
    }
    double dy() const {
        return ((IO_Distance &) mData[11]).get();
    }
    void dy(double v) {
        ((IO_Distance &) mData[11]).set(v);
    }
    double dz() const {
        return ((IO_Distance &) mData[13]).get();
    }
    void dz(double v) {
        ((IO_Distance &) mData[13]).set(v);
    }
    double vx() const {
        return ((IO_Velocity &) mData[15]).get();
    }
    void vx(double v) {
        ((IO_Velocity &) mData[15]).set(v);
    }
    double vy() const {
        return ((IO_Velocity &) mData[17]).get();
    }
    void vy(double v) {
        ((IO_Velocity &) mData[17]).set(v);
    }
    double vz() const {
        return ((IO_Velocity &) mData[19]).get();
    }
    void vz(double v) {
        ((IO_Velocity &) mData[19]).set(v);
    }
    unsigned int type() const {
        return mData[21];
    }
    void type(unsigned int  v) {
        mData[21] = v;
    }
    unsigned int shape() const {
        return ((IO_Type &) mData[21]).getShape();
    }
    unsigned int color() const {
        return ((IO_Type &) mData[21]).getColor();
    }
    void shape(unsigned int  v) {
        ((IO_Type &) mData[21]).setShape(v);
    }
    void color(unsigned int  v) {
        ((IO_Type &) mData[21]).setColor(v);
    }
    double lx() const {
        return ((IO_Distance &) mData[22]).get();
    }
    void lx(double v) {
        ((IO_Distance &) mData[22]).set(v);
    }
    double ly() const {
        return ((IO_Distance &) mData[24]).get();
    }
    void ly(double v) {
        ((IO_Distance &) mData[24]).set(v);
    }
    double lz() const {
        return ((IO_Distance &) mData[26]).get();
    }
    void lz(double v) {
        ((IO_Distance &) mData[26]).set(v);
    }
private:
    uint8_t mData[28];

};


};


#endif //V4R_STRUCTS_H
