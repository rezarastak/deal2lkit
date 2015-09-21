#ifndef dealii_assimp_interface_h
#define dealii_assimp_interface_h

#include <deal.II/grid/tria.h>

#include <deal2lkit/config.h>

using namespace dealii;

#ifdef D2K_WITH_ASSIMP
namespace AssimpInterface
{

  /**
   * Read in a file supported by Assimp, and generate a Triangulation
   * out of it.  If you specify a @p mesh_index, only the mesh with
   * the given index will be extracted, otherwise all meshes which are
   * present in the file will be used to generate the Triangulation.
   *
   * If @p remove_duplicates is set to true (the default), then
   * duplicated vertices will be removed if their distance is lower
   * than @p tol.
   *
   * Only the elements compatible with the given dimension and
   * spacedimension will be extracted from the mesh. All the other
   * elements are simply ignored by this algorithm. If your mesh
   * contains a mixture of triangles and quadrilaterals, for example,
   * only the quadrilaterals will be extracted. Careful that your mesh
   * may not make any sense if you are mixing compatible and
   * incompatible element types.
   *
   * A message is printed on screen telling you how many elements
   * where ignored. It is your responsability to make sure you feed
   * the right file to this function.
   */
  template <int dim, int spacedim>
  bool generate_triangulation(const std::string filename,
                              Triangulation<dim,spacedim> &tria,
                              int mesh_index=-1,
                              bool remove_duplicates=true,
                              double tol = 1e-12);

}
#endif

#endif
