import { useState } from 'react';
import './index.scss';

const App = () => {
  const [hours, setHours] = useState('00');
  const [minutes, setMinutes] = useState('00');

  return (
    <div id="ClockUpdater" className="container">
      <div className="row">
        <button
          id="hours-up-button"
          className="btn btn-outline-primary col"
        >
          &uarr;
        </button>

        <button
          id="minutes-up-button"
          className="btn btn-outline-primary col"
        >
          &uarr;
        </button>
      </div>

      <div className="row">
        <div id="clock" className="badge badge-primary col">
          {`${hours}:${minutes}`}
        </div>
      </div>

      <div className="row">
        <button
          id="hours-down-button"
          className="btn btn-outline-primary col"
        >
          &darr;
        </button>

        <button
            id="minutes-down-button"
            className="btn btn-outline-primary col"
          >
            &darr;
        </button>
      </div>
    </div>
  );
};

export default App;
