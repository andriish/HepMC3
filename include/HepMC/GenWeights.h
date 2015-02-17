// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC_GENWEIGHTS_H
#define HEPMC_GENWEIGHTS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace HepMC {


  /// Container for the Weights associated with an event or vertex.
  ///
  /// This class has both map-like and vector-like functionality.
  /// Named weights are now supported.
  class GenWeights {
  public:

    /// Default constructor of an empty GenWeights
    GenWeights() {  }

    /// Constructor from an array of weight values
    GenWeights(const std::vector<double>& wgts);

    /// Constructor from arrays of names and weight values
    GenWeights(const std::vector<std::string>& keys, const std::vector<double>& wgts )
      : m_weights(wgts), m_names(keys)
    {  }

    /// Constructor from array of pairs of names and weight values
    GenWeights(const std::vector< std::pair<std::string,double> >& keys_wgts ) {
      for (size_t i = 0; i < keys_wgts.size(); ++i)
        push_back(keys_wgts[i]);
    }

    /// Copy constructor
    GenWeights(const GenWeights& other)
      : m_weights(other.m_weights), m_names(other.m_names)
    {  }


    /// Copy assignment
    GenWeights& operator = (const GenWeights& wc) {
      GenWeights tmp(wc);
      swap(tmp);
      return *this;
    }

    /// Alternate assignment using a vector of doubles
    GenWeights& operator = (const std::vector<double>& in) {
      GenWeights tmp(in);
      swap(tmp);
      return *this;
    }

    /// Alternate assignment using a vector of pairs
    GenWeights& operator = (const std::vector< std::pair<std::string,double> >& in) {
      GenWeights tmp(in);
      swap(tmp);
      return *this;
    }



    /// Print weights
    void print(std::ostream& ostr=std::cout) const;
    /// Write weights in a readable table
    void write(std::ostream& ostr=std::cout) const;


    /// Indexing type
    typedef size_t size_type;
    /// Size of weight container
    size_t size() const { return m_weights.size(); }
    /// Return true if weight container is empty
    bool empty() const { return m_weights.empty(); }


    /// Get the available key names
    std::vector<std::string>& keys() { return m_names; }
    /// Get the available key names (const)
    const std::vector<std::string>& keys() const { return m_names; }
    /// Get the name of the given weight index
    std::string& key(size_t n) { return m_names[n]; }
    /// Get the name of the given weight index (const)
    const std::string& key(size_t n) const { return m_names[n]; }
    /// Get the index of the given key name (-1 if it doesn't exist)
    size_t index(const std::string& key) const;
    /// Check to see if a name exists
    bool has_key(const std::string& key) const { return std::find(m_names.begin(), m_names.end(), key) != m_names.end(); }


    /// Get the list of values
    std::vector<double>& values() { return m_weights; }
    /// Get the list of values (const)
    const std::vector<double>& values() const { return m_weights; }


    /// Push onto weight container with a key name and weight value
    void push_back(const std::string& key, double wgt);
    /// Push onto weight container with a paired key name and weight value
    void push_back(const std::pair<std::string,double>& key_wgt) { push_back(key_wgt.first, key_wgt.second); }
    /// Push onto weight container with a weight value and optional key name
    void push_back(double wgt, const std::string& key="") { push_back(key, wgt); }

    /// Set a key and weight value for a specific index
    void set(size_t n, const std::string& key, double wgt);
    /// Set a key and weight value for a specific index
    void set(size_t n, const std::pair<std::string,double>& key_wgt) { set(n, key_wgt.first, key_wgt.second); }
    /// Set a value (and optional key) for a specific index
    void set(size_t n, double wgt, const std::string& key="") { set(n, key, wgt); }

    /// Get the weight value at index n, with optional default return value
    double get(size_t n, double def=0) const;
    /// Get the weight value of key, with optional default return value
    double get(const std::string& key, double def=0) const;


    /// Swap
    void swap( GenWeights& other) {
      m_weights.swap( other.m_weights );
      m_names.swap( other.m_names );
    }

    /// Clear the weight container
    void clear() {
      m_weights.clear();
      m_names.clear();
    }


    /// Access the weight container by index
    double& operator[]( size_t n ) { return m_weights[n]; }
    /// Access the weight container by index
    const double& operator[]( size_t n ) const { return m_weights[n]; }
    /// Access the weight container by string key
    double& operator[]( const std::string& s );
    /// Access the weight container by string key
    const double& operator[]( const std::string& s ) const;

    /// Equality
    bool operator == ( const GenWeights& other) const;
    /// Inequality
    bool operator != ( const GenWeights& other) const { return !(*this == other ); }

    /// Returns the first (nominal) weight
    double& front() { return m_weights.front(); }
    /// Returns the first (nominal) weight (const)
    const double& front() const { return m_weights.front(); }


  private:

    std::vector<double> m_weights;
    std::vector<std::string> m_names;

  };


  #ifndef HEPMC_NO_DEPRECATED
  /// Alias for backward compatibility
  typedef GenWeights WeightContainer;
  #endif


} // HepMC

#endif  // HEPMC_GENWEIGHTS_H
