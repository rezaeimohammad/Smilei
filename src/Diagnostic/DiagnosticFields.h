#ifndef DIAGNOSTICFIELDS_H
#define DIAGNOSTICFIELDS_H

#include "Diagnostic.h"


class DiagnosticFields  : public Diagnostic {

public :
    
    DiagnosticFields( Params &params, SmileiMPI* smpi, Patch* patch, int diagId );
    DiagnosticFields();
    ~DiagnosticFields();
    
    virtual void openFile( Params& params, SmileiMPI* smpi, VectorPatch& vecPatches, bool newfile );
    virtual void closeFile();
    
    virtual bool prepare( Patch* patch, int timestep );
    
    virtual void run( Patch* patch, int timestep );
    
    virtual void write(int timestep);
    
protected :
    std::vector<Field*> fields_;
    std::vector<std::string> fieldsToDump;
    
    //! Property list for collective dataset write, set for // IO.
    hid_t write_plist;
    
    //! Basic Write of a field in the specified group of the global file
    virtual void writeFieldsSingleFileTime( Field* field, hid_t group_id ) = 0;
};

#endif

