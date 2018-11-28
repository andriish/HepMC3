// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2015 The HepMC collaboration (see AUTHORS for details)
//
/**
 *  @file GenParticle.cc
 *  @brief Implementation of \b class GenParticle
 *
 */
#include "HepMC/GenParticle.h"
#include "HepMC/GenVertex.h"
#include "HepMC/GenEvent.h"
#include "HepMC/Relatives.h"
#include "HepMC/Setup.h"
#include "HepMC/Attribute.h"

namespace HepMC {


GenParticle::GenParticle( const FourVector &mom, int pidin, int stat):
m_event(nullptr),
m_id(0) {
    m_data.pid               = pidin;
    m_data.momentum          = mom;
    m_data.status            = stat;
    m_data.is_mass_set       = false;
    m_data.mass              = 0.0;
}

GenParticle::GenParticle( const GenParticleData &dat ):
m_event(nullptr),
m_id(0),
m_data(dat) {
}

double GenParticle::generated_mass() const {
    if(m_data.is_mass_set) return m_data.mass;
    else                   return m_data.momentum.m();
}

void GenParticle::set_pid(int pidin) {
    m_data.pid = pidin;
}

void GenParticle::set_status(int stat) {
    m_data.status = stat;
}

void GenParticle::set_momentum(const FourVector& mom) {
    m_data.momentum = mom;
}

void GenParticle::set_generated_mass(double m) {
    m_data.mass        = m;
    m_data.is_mass_set = true;
}

void GenParticle::unset_generated_mass() {
    m_data.mass        = 0.;
    m_data.is_mass_set = false;
}
  
GenVertexPtr GenParticle::production_vertex() {
    return m_production_vertex.lock();
}

ConstGenVertexPtr GenParticle::production_vertex() const {
    return std::const_pointer_cast<const GenVertex>(m_production_vertex.lock());
}

GenVertexPtr GenParticle::end_vertex() {
    return m_end_vertex.lock();
}

ConstGenVertexPtr GenParticle::end_vertex() const {
    return std::const_pointer_cast<const GenVertex>(m_end_vertex.lock());
}

vector<GenParticlePtr> GenParticle::parents(){
    return (m_production_vertex.expired())? vector<GenParticlePtr>() : Relatives::PARENTS(shared_from_this());
}

vector<ConstGenParticlePtr> GenParticle::parents() const{
    return (m_production_vertex.expired()) ? vector<ConstGenParticlePtr>() : Relatives::PARENTS(shared_from_this());
}
  
vector<GenParticlePtr> GenParticle::children(){
    return (m_end_vertex.expired())? vector<GenParticlePtr>() : Relatives::CHILDREN(shared_from_this());
}

vector<ConstGenParticlePtr> GenParticle::children() const{
    return (m_end_vertex.expired()) ? vector<ConstGenParticlePtr>() : Relatives::CHILDREN(shared_from_this());
}

vector<GenParticlePtr> GenParticle::ancestors() {
  return (m_production_vertex.expired()) ? vector<GenParticlePtr>() : Relatives::ANCESTORS(shared_from_this());
}

vector<ConstGenParticlePtr> GenParticle::ancestors() const {
  return (m_production_vertex.expired()) ? vector<ConstGenParticlePtr>() : Relatives::ANCESTORS(shared_from_this());
}

vector<GenParticlePtr> GenParticle::descendants() {
  return (m_end_vertex.expired()) ? vector<GenParticlePtr>() : Relatives::DESCENDANTS(shared_from_this());
}

vector<ConstGenParticlePtr> GenParticle::descendants() const {
  return (m_end_vertex.expired()) ? vector<ConstGenParticlePtr>() : Relatives::DESCENDANTS(shared_from_this());
}

void GenParticle::set_gen_event(GenEvent *evt){
  m_event = evt;
  return;
}

void GenParticle::set_id(int id){
  m_id = id;
  return;
}

void GenParticle::set_production_vertex(GenVertexPtr vtx){
  m_production_vertex = vtx;
  return;
}
 
void GenParticle::set_end_vertex(GenVertexPtr vtx){
  m_end_vertex = vtx;
  return;
}
 
bool GenParticle::add_attribute(std::string name, shared_ptr<Attribute> att) {
  if ( !parent_event() ) return false;
  parent_event()->add_attribute(name, att, id());
  return true;
}

vector<string> GenParticle::attribute_names() const {
  if ( parent_event() ) return parent_event()->attribute_names(id());

  return vector<string>();
}

void GenParticle::remove_attribute(std::string name) {
  if ( parent_event() ) parent_event()->remove_attribute(name, id());
}

string GenParticle::attribute_as_string(string name) const {
    return parent_event() ? parent_event()->attribute_as_string(name, id()) : string();
}

} // namespace HepMC
