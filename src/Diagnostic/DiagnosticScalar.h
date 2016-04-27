#ifndef DIAGNOSTICSCALAR_H
#define DIAGNOSTICSCALAR_H

#include "Diagnostic.h"

#include "Params.h"
#include "Patch.h"
#include "SmileiMPI.h"


//! double-int structure to communicate min/max and location trough MPI 
struct val_index
{
    //! min/max 
    double val;
    //! cell location index
    int index;
};


class DiagnosticScalar : public Diagnostic {
    friend class SmileiMPI;

public :
    //! Default constructor
    DiagnosticScalar( Params &params, SmileiMPI* smpi, Patch* patch, int diagId );
    //! Cloning constructor
    DiagnosticScalar( DiagnosticScalar * scalar );
    //! Default destructor
    ~DiagnosticScalar();
    
    virtual void openFile( Params& params, SmileiMPI* smpi, VectorPatch& vecPatches, bool newfile );
    
    virtual void closeFile();
    
    virtual bool prepare( Patch* patch, int timestep );
    
    virtual void run( Patch* patch, int timestep );
    
    virtual void write(int timestep);
    
    //! get a particular scalar
    double getScalar(std::string name);
    
    //! every for the standard pic timeloop output
    unsigned int print_every;
    
    //! initial energy (kinetic + EM)
    double Energy_time_zero;
    
    //! energy used for the normalization of energy balance (former total energy)
    double EnergyUsedForNorm;
    
    // Specific methods
    void compute( Patch* patch, int timestep );
    
private :
    
    //! set a particular scalar
    void setScalar(std::string name, double value);
    
    //! increment a particular scalar
    void incrementScalar(std::string name, double value);
    
    //! append to outlist
    void append(std::string, double);
    
    //! prepend to outlist
    void prepend(std::string, double);
    
    //! check if key is allowed
    bool allowedKey(std::string);
    
    bool defined(std::string);
    
    //! write precision
    unsigned int precision;
    
    //! list of keys for scalars to be written
    std::vector<std::string> vars;
    
    //! these are lists to keep variable names and values
    std::vector<std::string> out_key;
    std::vector<double>      out_value;
    //! width of each field
    std::vector<unsigned int> out_width;
    
    //! copied from params
    double cell_volume;
    
    //! this is copied from params
    double res_time;
    
    double dt;
    
    //! output stream
    std::ofstream fout;
    



};

#endif

