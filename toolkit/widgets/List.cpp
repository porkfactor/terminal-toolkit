#include <terminal/toolkit/List.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/SelectionListener.hpp>
#include <algorithm>

namespace terminal {
  namespace toolkit {
    struct List::impl {

      std::vector<std::wstring> items_;
    };

    List::List(Composite *parent) :
      Scrollable(parent)
    {

    }

    void List::add(const std::wstring &item) {
      pimpl_->items_.push_back(item);
    }

    void List::add(const std::wstring &item, Control::index_t index) {

    }

    void List::addSelectionListener(SelectionListener *listener) {

    }

    Point List::computeSize(int wHint, int hHint, bool changed) const {

    }

    void List::deselect(Control::index_t index) {

    }

    void List::deselect(const std::vector<Control::index_t> &indices) {

    }

    void List::deselect(Control::index_t start, Control::index_t end) {

    }

    void List::deselectAll() {

    }

    Control::index_t List::getFocusIndex() const {
      Control::index_t rv(Control::npos);

      return(rv);
    }

    std::wstring List::getItem(Control::index_t index) const {
      std::wstring rv;

      return(rv);
    }

    uint32_t List::getItemCount() const {
      uint32_t rv(0);

      rv = pimpl_->items_.size();

      return(rv);
    }

    uint32_t List::getItemHeight() const {
      uint32_t rv(0);

      return(rv);
    }

    std::vector<std::wstring> List::getItems() const {
      return(pimpl_->items_);
    }

    std::vector<std::wstring> List::getSelection() const {
      std::vector<std::wstring> rv;

      return(rv);
    }

    Control::index_t List::getSelectionCount() const {
      Control::index_t rv(Control::npos);

      return(rv);
    }

    Control::index_t List::getSelectionIndex() const {
      Control::index_t rv(Control::npos);

      return(rv);
    }

    std::vector<Control::index_t> List::getSelectionIndices() const {
      return(std::vector<Control::index_t>());
    }

    Control::index_t List::getTopIndex() const {
      Control::index_t rv(Control::npos);

      return(rv);
    }

    Control::index_t List::indexOf(const std::wstring &string) const {
      Control::index_t rv(Control::npos);
      decltype(pimpl_->items_.begin()) it;

      if((it = std::find(pimpl_->items_.begin(), pimpl_->items_.end(), string)) != pimpl_->items_.end()) {
        rv = std::distance(pimpl_->items_.begin(), it);
      }

      return(rv);
    }

    Control::index_t List::indexOf(const std::wstring &string, Control::index_t start) const {
      Control::index_t rv(Control::npos);

      return(rv);
    }

    bool List::isSelected(Control::index_t index) const {
      return(false);
    }

    void List::remove(Control::index_t index) {
      pimpl_->items_.erase(pimpl_->items_.begin() + index);
    }

    void List::remove(std::vector<Control::index_t> indices) {

    }

    void List::remove(Control::index_t start, Control::index_t end) {
      pimpl_->items_.erase(pimpl_->items_.begin() + start, pimpl_->items_.begin() + end);
    }

    void List::remove(std::wstring string) {

    }

    void List::removeAll() {
      pimpl_->items_.clear();
    }

    void List::removeSelectionListener(SelectionListener *listener) {

    }

    void List::select(Control::index_t index) {

    }

    void List::select(std::vector<Control::index_t> indices) {

    }

    void List::select(Control::index_t start, Control::index_t end) {

    }

    void List::selectAll() {

    }

    void List::setItem(Control::index_t index, std::wstring string) {

    }

    void List::setItems(const std::vector<std::wstring> &) {

    }

    void List::setSelection(Control::index_t index) {

    }

    void List::setSelection(const std::vector<Control::index_t> &indices) {

    }

    void List::setSelection(Control::index_t start, Control::index_t end) {

    }

    void List::setSelection(const std::vector<std::wstring> &indices) {

    }
    void List::setTopIndex(Control::index_t index) {

    }

    void List::showSelection() {

    }
  }
}
