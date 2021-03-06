# .onLoad <- function(libname, pkgname) { Rcpp::loadRcppModules() }
#' @importFrom "Rcpp" loadModule
.onLoad <- function(libname, pkgname) {
  modules <- paste0("stan_fit4", names(stanmodels), "_mod")
  for (m in modules) loadModule(m, what = TRUE)
}
