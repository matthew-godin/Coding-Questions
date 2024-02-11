import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
})
export class AppComponent {
  hours = '00';
  minutes = '00';

  handleHoursUpButtonClick() {
    let hoursVal = parseInt(this.hours) + 1;
    if (hoursVal > 23) {
      hoursVal = 0;
    }
    this.hours = hoursVal.toString();
    if (this.hours.length < 2) {
      this.hours = '0' + this.hours;
    }
  }

  handleHoursDownButtonClick() {
    let hoursVal = parseInt(this.hours) - 1;
    if (hoursVal < 0) {
      hoursVal = 23;
    }
    this.hours = hoursVal.toString();
    if (this.hours.length < 2) {
      this.hours = '0' + this.hours;
    }
  }

  handleMinutesUpButtonClick() {
    let minutesVal = parseInt(this.minutes) + 1;
    if (minutesVal > 59) {
      minutesVal = 0;
    }
    this.minutes = minutesVal.toString();
    if (this.minutes.length < 2) {
      this.minutes = '0' + this.minutes;
    }
  }

  handleMinutesDownButtonClick() {
    let minutesVal = parseInt(this.minutes) - 1;
    if (minutesVal < 0) {
      minutesVal = 59;
    }
    this.minutes = minutesVal.toString();
    if (this.minutes.length < 2) {
      this.minutes = '0' + this.minutes;
    }
  }
}
