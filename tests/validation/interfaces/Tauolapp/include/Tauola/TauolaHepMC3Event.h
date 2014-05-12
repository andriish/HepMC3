#ifndef _TauolaHepMC3Event_h_included_
#define _TauolaHepMC3Event_h_included_

/**
 * @class TauolaHepMC3Event
 *
 * @brief Interface to HepMC3::GenEvent objects
 *
 * This class implements the virtual methods of
 * TauolaEvent. In this way it provides an
 * interface between the generic TauolaEvent class
 * and a HepMC3::GenEvent object.
 *
 * This code is licensed under GNU General Public Licence.
 * For more informations, see: http://www.gnu.org/licenses/
 */

#include <iostream>
#include "HepMC3/GenEvent.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenParticle.h"
#include "Tauola/TauolaEvent.h"
#include "Tauola/TauolaParticle.h"
#include "Tauola/TauolaHepMC3Particle.h"

namespace Tauolapp
{

class TauolaHepMC3Event : public TauolaEvent{

 public:

  /** Constructor which keeps a pointer to the HepMC3::GenEvent*/
  TauolaHepMC3Event(HepMC3::GenEvent * event);

  ~TauolaHepMC3Event();

  /** Returns the HepMC3::GenEvent */
  HepMC3::GenEvent * getEvent();

  /** Implementation of TauolaEvent virtual method.
      This returns a list of particles in the event with
      pdg id = "pdgID". */
  std::vector<TauolaParticle*> findParticles(int pdgID);

  /** Implementation of TauolaEven virtual method.
      This returns a list of particles in the event with
      pdg id = "pdgID" and stable status code. */
  std::vector<TauolaParticle*> findStableParticles(int pdgID);

  /** Overriding of TauolaEvent decayEndgame method.
      Converts the momentum and length units */
  void eventEndgame();

 private:

  /** The event */
  HepMC3::GenEvent * m_event;
  /** List of particles to be decayed */
  std::vector<TauolaParticle*> m_tau_list;
  /** Momentum unit name */
  string m_momentum_unit;
  /** Length unit name */
  string m_length_unit;

};

} // namespace Tauolapp
#endif

